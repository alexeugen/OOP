#include "Item3.h"

Item3::Item3(int l, int c)
{
  _lin = l;
  _col = c;
  _type = new char[100];
  strcpy(_type, "Brainy");
  _symbol = 'b';
}
