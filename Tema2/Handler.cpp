#include "Handler.h"
#include "Agent.h"
#include "Agent1.h"

Handler::Handler(const char* file_name)
{
  _in = fopen(file_name, "r");
  _Map1 = new Map(15, 15);

  _Agents = (Agent**)malloc(sizeof(Agent*) * 100);
  _Items = (Item**)malloc(sizeof(Item*) * 100);

  fscanf(_in, "%d", &_nrA1);
  for(int i = 0; i < _nrA1; i++)
  {
    char *s = new char[100];
    int x, y;
    fscanf(_in, "%s%d%d", s, &x, &y);
    _Agents[i] = new Agent1(_Map1,x,y);
    _Map1->Set(x, y, _Agents[i]->GetSymbol());
  }

  fscanf(_in, "%d", &_nrA2);
  for(int i = _nrA1; i < _nrA1 + _nrA2; i++)
  {
    char *s = new char[100];
    int x, y;
    fscanf(_in, "%s%d%d", s, &x, &y);
    _Agents[i] = new Agent2(_Map1,x,y);
    _Map1->Set(x, y, _Agents[i]->GetSymbol());
  }

  fscanf(_in, "%d", &_nrA3);
  for(int i = _nrA1 + _nrA2; i < _nrA1 + _nrA2 + _nrA3; i++)
  {
    char *s = new char[100];
    int x, y;
    fscanf(_in, "%s%d%d", s, &x, &y);
    _Agents[i] = new Agent3(_Map1,x,y);
    _Map1->Set(x, y, _Agents[i]->GetSymbol());
  }

  fscanf(_in, "%d", &_nrItems);
  for(int i = 0; i < _nrItems; i++)
  {
    char *s = new char[100];
    int x, y;
    fscanf(_in, "%s%d%d", s, &x, &y);
    if(!strcmp(s, "Shield"))
      _Items[i] = new Item1(x,y);
    else if (!strcmp(s, "Extended"))
      _Items[i] = new Item2(x,y);
    else if (!strcmp(s, "Brainy"))
      _Items[i] = new Item3(x,y);

    _Map1->Set(x, y, _Items[i]->GetSymbol());
  }


  _nrA = _nrA1 + _nrA2 + _nrA3;
  _Map1->Display();
}

Handler::~Handler()
{
  for(int i = 0; i < _nrA; i++)
    delete _Agents[i];
  delete[] _Agents;

  for(int i = 0; i < _nrItems; i++)
    delete _Items[i];
  delete[] _Items;

  delete _Map1;
}


/*** Play not finished* *******************************************/
/*
void Handler::Play(const int time_interval)
{
  int **moves;             // matrice in care pun indicele agentului
  moves = new int*[_Map1->GetHeight()];
  for(int i = 0; i<_Map1->GetHeight(); i++)
    moves[i] = new int[_Map1->GetWidth()];

  while(1)
  {
    Log Logs;

    printf("\033[2J");

    _Map1->Reset();
    for(int i = 0; i<_nrA; i++)
    {
      if(_Agents[i] != NULL)
      {
        int lin, col;
        moves[_Agents[i]->GetLin()][_Agents[i]->GetCol()] = 0;
        _Agents[i]->Move(lin, col);
        if(moves[lin][col])           // Stergerea agentului care era acolo
        {
            delete  _Agents[moves[lin][col] - 1];
            _Agents[moves[lin][col] - 1] = NULL;

            Logs.AddDied(my_itoa(moves[lin][col]-1));
        }
        Logs.AddMoved(my_itoa(i), my_itoa(lin), my_itoa(col));

        _Map1->Set(lin, col, _Agents[i]->GetSymbol());

        moves[lin][col] = i + 1;
      }
    }


    _Map1->Display();
    Logs.Print();
    printf("\033[2J");
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    sleep_for(nanoseconds(10));
    sleep_until(system_clock::now() + nanoseconds(100000000 * time_interval));
  }

  for(int i = 0; i < _Map1->GetHeight(); i++)
    delete[] moves[i];
  delete[] moves;
}
*/

void Handler::PlaySeq()
{
  int **moves;             // matrice in care pun indicele agentului
  moves = new int*[_Map1->GetHeight()];
  for(int i = 0; i<_Map1->GetHeight(); i++)
    moves[i] = new int[_Map1->GetWidth()];

  char c;
  cin>>c;
  while(c == 'p')
  {
    Log Logs;

    printf("\033[2J");

    _Map1->Reset();

    for(int i = 0; i < _nrItems; i++)
    {
      if(_Items[i] != NULL)
        moves[_Items[i]->GetLin()][_Items[i]->GetCol()] = 1001 + i;
    }



    for(int i = 0; i<_nrA; i++)
    {
      if(_Agents[i] != NULL)
      {
        int lin, col;
        moves[_Agents[i]->GetLin()][_Agents[i]->GetCol()] = 0;
        _Agents[i]->Move(lin, col);
        if(moves[lin][col] != 0)           // Luarea unui shield sau stergerea agentului care era acolo
        {
          if(moves[lin][col] >= 1001)    //Daca e un item
          {
            if(!strcmp("Extended", _Items[moves[lin][col]-1001]->GetType()))
            {
              _Agents[i]->SetExtended();
              Logs.AddExtended(my_itoa(i));
            }
            else if(!strcmp("Shield", _Items[moves[lin][col]-1001]->GetType()))
            {
              _Agents[i]->SetShield();
              Logs.AddShielded(my_itoa(i));
            }
            else if(!strcmp("Brainy", _Items[moves[lin][col]-1001]->GetType()))
            {
              _Agents[i]->SetBrainy();
              Logs.AddBrainy(my_itoa(i));
            }
            delete _Items[moves[lin][col]-1001];
            _Items[moves[lin][col]-1001] = NULL;
            moves[lin][col] = 0;
          }
          else                                 //Daca e un alt Agent
          {
            if(!_Agents[moves[lin][col] - 1]->CheckShield())
            {
              delete  _Agents[moves[lin][col] - 1];
              _Agents[moves[lin][col] - 1] = NULL;
              Logs.AddDied(my_itoa(moves[lin][col]-1));
            }
            else
            {
              Logs.AddBlocked(my_itoa(moves[lin][col]-1));
              _Agents[moves[lin][col] - 1]->ClearShield();

            }
          }
        }
        Logs.AddMoved(my_itoa(i), my_itoa(lin), my_itoa(col));

        _Map1->Set(lin, col, _Agents[i]->GetSymbol());

        moves[lin][col] = i + 1;
      }
    }

    for(int i = 0; i < _nrItems; i++)
    {
      if(_Items[i] != NULL)
      _Map1->Set(_Items[i]->GetLin(), _Items[i]->GetCol(), _Items[i]->GetSymbol());
    }


    _Map1->Display();
    Logs.Print();
    cin>>c;
    if(c == 's')
      break;
    printf("\033[2J");
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds



  }

  for(int i = 0; i < _Map1->GetHeight(); i++)
    delete[] moves[i];
  delete[] moves;

}



/******************* PRIVATE FUNCTIONS **********************/
void Handler::reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}

char* Handler::my_itoa(int num)  //itoa code was shamefully coppied from geeksforgeeks
{                                         // and a little modified
    char *str = new char [20];
    int i = 0;
    bool isNegative = false;

    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (num < 0)
    {
        isNegative = true;
        num = -num;
    }

    while (num != 0)
    {
        int rem = num % 10;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/10;
    }


    if (isNegative)
        str[i++] = '-';

    str[i] = '\0';


    reverse(str, i);

    return str;
}
