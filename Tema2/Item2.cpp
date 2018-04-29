#include "Item2.h"

Item2::Item2(int l, int c)
{
  _lin = l;
  _col = c;
  _type = new char[100];
  strcpy(_type, "Extended");
  _symbol = 'e';
}
