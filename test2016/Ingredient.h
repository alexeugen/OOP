#ifndef _INGREDIENT_H
#define _INGREDIENT_H

#include <string.h>
#include <iostream>

using namespace std;

class Ingredient{
public:
  Ingredient();
  Ingredient(const char* den, double pret, int cant, const char mas[10]);
//  Ingredient(const Ingredient& ing2);
  ~Ingredient();

  Ingredient operator + (int x);
  Ingredient operator ++ (int);
  Ingredient operator -= (double);
  friend ostream& operator << (ostream& stream, const Ingredient& ing);
  friend istream& operator >> (istream& stream, Ingredient& ing);


private:
  char* _denIng;
  double _pretIng;
  int _cantIng;
   char _masIng[10];
};

#endif
