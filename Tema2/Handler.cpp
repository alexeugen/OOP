#include "Handler.h"
#include "Agent.h"
#include "Agent1.h"

Handler::Handler(const char* file_name)
{
  _in = fopen(file_name, "r");
  _Map1 = new Map(15, 15);


  fscanf(_in, "%d", &_nrA1);
  _Agents1 = (Agent1**)malloc(sizeof(Agent1*)*100);
  for(int i = 0; i < _nrA1; i++)
  {
    char *s = new char[100];
    int x, y;
    fscanf(_in, "%s%d%d", s, &x, &y);
    _Agents1[i] = new Agent1(_Map1,x,y);
  }

}

Handler::~Handler()
{

}

void Handler::Play(const int time_interval)
{
  while(1)
  {
    char **moves;
    moves = new char*[100];
    for(int i = 0; i<_nrA1; i++)
      moves[i] = NULL;



    printf("\033[2J");
    _Map1->Reset();
    for(int i = 0; i<_nrA1; i++)
    {
      char *s = _Agents1[i]->Move();
      if(s)
        moves[i] = s;

    }


    for(int i = 0; i < _nrA1; i++)
      for(int j = i+1; j < _nrA1; j++)
        if(moves[i] && moves[j])
          if(!strcmp(moves[i], moves[j]))
            _Agents1[i]->Died();


    for(int i = 0; i<_nrA1; i++)
    {
        delete[] moves[i];

    }


    _Map1->Display();
    printf("\033[2J");
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds

    sleep_for(nanoseconds(10));
    sleep_until(system_clock::now() + nanoseconds(100000000 * time_interval));
  }
}
