#ifndef _HANDLER_H
#define _HANDLER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <chrono>
#include <thread>
#include "Map.h"
#include "Agent1.h"

using namespace std;

class Handler{
public:
  Handler(const char *file_name);
  ~Handler();
  void Play(int time_interval);



private:
  FILE *_in;
  Agent1 **_Agents1;
  Map *_Map1;
  int _nrA1, _nrA2, _nrA3; 
};



#endif
