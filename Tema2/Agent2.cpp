#include "Agent2.h"


Agent2::Agent2()
{

}

Agent2::Agent2(Map *Map1, int poz_x, int poz_y)  : Agent(poz_x, poz_y)
{
  _Map1 = Map1;
  _symbol = '#';
  _shield = 0;
  _extended = 0;
  _brainy = 0;
}

Agent2::~Agent2()
{

}

void Agent2::Move(int &l, int &c)
{

    _setAvailable();

    l = _poz_x;
    c = _poz_y;
}


/*********************** Private functions ************************/
void Agent2::_setAvailable()
{
  int v[]={0,1,2,3};
  srand(clock());
  random_shuffle(&v[0], &v[4]);

  if(!_extended)
    _getAvPos(_poz_x, _poz_y);
  else
    _getAvPosExtended(_poz_x, _poz_y);

    int q = 0;
    if(_brainy)
    {
      for(int i = 0; i <= 3; i++)
      {

          if(_avPos.p[i].x < _Map1->GetWidth() && _avPos.p[i].y < _Map1->GetHeight() && _avPos.p[i].x >= 0 && _avPos.p[i].y >= 0)
          {
            if(_Map1->GetC(_avPos.p[i].x, _avPos.p[i].y) != '~')
            {
              _poz_x = _avPos.p[i].x;
              _poz_y = _avPos.p[i].y;
              q = 1;
              break;
            }
          }
      }
    }
    if(!q)
    for(int i = 0; i <= 3; i++)
    {

        if(_avPos.p[v[i]].x < _Map1->GetWidth() && _avPos.p[v[i]].y < _Map1->GetHeight() && _avPos.p[v[i]].x >= 0 && _avPos.p[v[i]].y >= 0)
        {
          _poz_x = _avPos.p[v[i]].x;
          _poz_y = _avPos.p[v[i]].y;

          break;
        }
    }
}

void Agent2::_getAvPos(int poz_x, int poz_y)
{
  _avPos.p[0].x = poz_x + 1;
  _avPos.p[0].y = poz_y;
  _avPos.p[1].x = poz_x - 1;
  _avPos.p[1].y = poz_y;
  _avPos.p[2].x = poz_x;
  _avPos.p[2].y = poz_y - 1;
  _avPos.p[3].x = poz_x;
  _avPos.p[3].y = poz_y + 1;
}

void Agent2::_getAvPosExtended(int poz_x, int poz_y)
{
  _avPos.p[0].x = poz_x + 2;
  _avPos.p[0].y = poz_y;
  _avPos.p[1].x = poz_x - 2;
  _avPos.p[1].y = poz_y;
  _avPos.p[2].x = poz_x;
  _avPos.p[2].y = poz_y - 2;
  _avPos.p[3].x = poz_x;
  _avPos.p[3].y = poz_y + 2;
}
