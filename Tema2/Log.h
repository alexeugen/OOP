#ifndef _LOG_H
#define _LOG_H

#include <iostream>
#include <cstring>

using namespace std;

class Log{
public:
  Log();
  ~Log();
  void Add(char *s);
  void AddDied(char* i);
  void AddMoved(char* i, char* l, char* c);
  void Print();

private:
  char **_logs;
  int _nrlogs;
};

#endif
