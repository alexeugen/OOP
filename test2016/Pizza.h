#ifndef _PIZZA_H
#define _PIZZA_H

#include "Ingredient.h"

class Pizza{
public:
  Pizza();
  Pizza(const char* den, Ingredient* lista, int nring, bool veg);
  ~Pizza();
private:
  int _codPizza;
  char* _denPizza;
  Ingredient* _ingPizza;
  int _nringPizza;
  bool _vegPizza;

};

#endif
