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

class Agent1 : public Agent{
public:
  Agent1();
  Agent1(Map *Map1, int poz_x, int poz_y);
  ~Agent1();
  char* Move() override;
  void Died() override;


protected:
  void _setAvailable() override;
  void _getAvPos(int poz_x, int poz_y) override;

};

#endif
