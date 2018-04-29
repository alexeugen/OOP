#ifndef _AGENT2_H
#define _AGENT2_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Map.h"
#include "Agent.h"
using namespace std;

class Agent2 : public Agent{
public:
  Agent2();
  Agent2(Map *Map1, int poz_x, int poz_y);

  ~Agent2();

  void Move(int &l, int &c) override;



protected:
  void _setAvailable() override;
  void _getAvPos(int poz_x, int poz_y) override;
  void _getAvPosExtended(int poz_x, int poz_y) override;

};

#endif
