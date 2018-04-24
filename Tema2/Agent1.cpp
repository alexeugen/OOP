#include "Agent1.h"


Agent1::Agent1()
{

}

Agent1::Agent1(Map *Map1, int poz_x, int poz_y)
{
  _Map1 = Map1;
  _poz_x = poz_x;
  _poz_y = poz_y;
}

Agent1::~Agent1()
{

}

char* Agent1::Move()
{
  if(_dead == false)
  {
    _setAvailable();

    _Map1->_matrix[_poz_x][_poz_y] = '@';
    char* s = new char[30];
    strcpy(s, my_itoa(_poz_x));
    strcat(s, " ");
    strcat(s, my_itoa(_poz_y));
    return s;
  }
  return NULL;
}


void Agent1::Died()
{
  _dead = true;
}

/*********************** Private functions ************************/
void Agent1::_setAvailable()
{
  int v[]={0,1,2,3};
  srand(clock());
  random_shuffle(&v[0], &v[4]);

  _getAvPos(_poz_x, _poz_y);

  for(int i = 0; i <= 3; i++)
  {

      if(_avPos.p[v[i]].x < _Map1->_width && _avPos.p[v[i]].y < _Map1->_height && _avPos.p[v[i]].x >= 0 && _avPos.p[v[i]].y >= 0)
      {
        _poz_x = _avPos.p[v[i]].x;
        _poz_y = _avPos.p[v[i]].y;

        break;
      }
  }
}

void Agent1::_getAvPos(int poz_x, int poz_y)
{
  _avPos.p[0].x = poz_x + 1;
  _avPos.p[0].y = poz_y + 1;
  _avPos.p[1].x = poz_x - 1;
  _avPos.p[1].y = poz_y - 1;
  _avPos.p[2].x = poz_x + 1;
  _avPos.p[2].y = poz_y - 1;
  _avPos.p[3].x = poz_x - 1;
  _avPos.p[3].y = poz_y + 1;
}
