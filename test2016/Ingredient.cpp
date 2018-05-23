#include "Ingredient.h"

Ingredient::Ingredient()
{

}

Ingredient::Ingredient(const char* den, double pret, int cant, const char mas[10])
: _pretIng(pret), _cantIng(cant)
{
  _denIng = new char[strlen(den) + 1];
  strcpy(_denIng, den);
  strcpy(_masIng, mas);
}
/*
Ingredient::Ingredient(const Ingredient& ing2)
{
  _denIng = new char[strlen(ing2._denIng) + 1];
  strcpy(_denIng, ing2._denIng);
  _pretIng = ing2._pretIng;
  _cantIng = ing2._cantIng;
  strcpy(_masIng, ing2._masIng);
}*/
Ingredient::~Ingredient()
{

}

Ingredient Ingredient::operator + (int x)
{
  Ingredient ing(_denIng, _pretIng, _cantIng, _masIng);
  ing._cantIng += x;
  return ing;
}

Ingredient Ingredient::operator ++ (int)
{
  _cantIng++;
  return *this;
}

Ingredient Ingredient::operator -= (double x)
{
  _pretIng -= x;
  return *this;
}

ostream& operator << (ostream& stream, const Ingredient& ing)
{
  stream << ing._denIng << ", " << ing._pretIng << ", " << ing._cantIng << ", " << ing._masIng<< "\n";
  return stream;
}

istream& operator >> (istream& stream, Ingredient& ing)
{
  char den[100];
  stream>>den;
  ing._denIng = new char[strlen(den) + 1];
  strcpy(ing._denIng, den);
  stream>>ing._pretIng;
  stream>>ing._cantIng;
  stream>>ing._masIng;
}
