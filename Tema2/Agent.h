#ifndef _AGENT_H
#define _AGENT_H

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include "Map.h"
using namespace std;

class Agent{
public:
  virtual char* Move() = 0;
  virtual void Died() = 0;

protected:
  virtual void _setAvailable() = 0;
  virtual void _getAvPos(int poz_x, int poz_y) = 0;
  void reverse(char str[], int length);
  char* my_itoa(int num);

  bool _dead = false;
  Map *_Map1;
  int _poz_x;
  int _poz_y;



  struct poz{
    int x,y;
    poz(){}
    poz(int a, int b)
    {
        x = a;
        y = b;
    }
  };

  struct availablePositions{
    poz p[4];
  }_avPos;


};



#endif
