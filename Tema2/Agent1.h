#ifndef _AGENT1_H
#define _AGENT1_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Map.h"
#include "Agent.h"
using namespace std;

class Agent1 : public Agent{
public:
  Agent1();
  Agent1(Map *Map1, int poz_x, int poz_y);

  ~Agent1();

  void Move(int &l, int &c) override;



protected:
  void _setAvailable() override;
  void _getAvPos(int poz_x, int poz_y) override;

};

#endif
