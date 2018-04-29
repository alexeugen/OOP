#include "Item1.h"

Item1::Item1(int l, int c)
{
  _lin = l;
  _col = c;
  _type = new char[100];
  strcpy(_type, "Shield");
  _symbol = 's';
}
