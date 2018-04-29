#ifndef _AGENT3_H
#define _AGENT3_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Map.h"
#include "Agent.h"
using namespace std;

class Agent3 : public Agent{
public:
  Agent3();
  Agent3(Map *Map1, int poz_x, int poz_y);

  ~Agent3();

  void Move(int &l, int &c) override;



protected:
  void _setAvailable() override;
  void _getAvPos(int poz_x, int poz_y) override;

};

#endif
