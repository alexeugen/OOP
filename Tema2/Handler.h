#ifndef _HANDLER_H
#define _HANDLER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <chrono>
#include <thread>
#include "Map.h"
#include "Agent1.h"
#include "Log.h"

using namespace std;

class Handler{
public:
  Handler(const char *file_name);
  ~Handler();
  void Play(int time_interval); //redare runde la interval de timp
  void PlaySeq();//redare runde secventiala la apasare de buton



private:
  void reverse(char str[], int length);
  char* my_itoa(int num);

  FILE *_in;
  Agent **_Agents;
  Map *_Map1;
  int _nrA1, _nrA2, _nrA3;
};



#endif
