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
  Agent();
  Agent(int pozx, int pozy);
  virtual void Move(int &l, int &c) = 0;
  char GetSymbol() const {return _symbol;}
  int GetLin() const {return _poz_x;}
  int GetCol() const {return _poz_y;}
  int CheckShield();
  void SetShield();
  void ClearShield();
  void SetExtended();

  void SetBrainy();



protected:
  virtual void _getAvPosExtended(int poz_x, int poz_y) = 0;
  virtual void _getAvPos(int poz_x, int poz_y) = 0;   // calculeaza posibilele pozitii
  virtual void _setAvailable() = 0;  // alege pozitia

  void reverse(char str[], int length);
  char* my_itoa(int num);

  char _symbol;
  int _shield;
  Map *_Map1;
  int _poz_x;
  int _poz_y;
  int _extended;
  int _brainy;

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
