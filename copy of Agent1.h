#ifndef _AGENT1_H
#define _AGENT1_H

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include "Map.h"
#include "Agent.h"
using namespace std;

class Agent1{
public:
  Agent1();
  Agent1(Map *Map1, int poz_x, int poz_y);
  ~Agent1();
  void Move();



private:
  void _setAvailable();


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
    void Get(int poz_x, int poz_y);
  }_avPos;


};

#endif
