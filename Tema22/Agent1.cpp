#include "Agent1.h"

Agent1::Agent1()
{

}

Agent1::Agent1(int poz_x, int poz_y)
{
  _poz_x = poz_x;
  _poz_y = poz_y;
}

void Agent1::Move()
{

}



/******** Private functions ********/
void Agent1::_setAvailable()
{
  int v[]={1,2,3,4};
  random_shuffle(&v[0], &v[3]);

  for(int i = 0; i <= 3; i++)
  {
    cout<<v[i];
  }
}

void Agent1::availablePositions::Get()
{
  p[0].x = _poz_x + 1;
  p[0].y = _poz_y + 1;
  p[1].x = _poz_x - 1;
  p[1].y = _poz_y - 1;
  p[2].x = _poz_x + 1;
  p[2].y = _poz_y - 1;
  p[3].x = _poz_x - 1;
  p[3].y = _poz_y + 1;
}
