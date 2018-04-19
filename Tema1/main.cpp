#include <iostream>
#include "PQueue.h"

using namespace std;

int main()
{
  PQueue p;
  p.insert(5, 6);
  p.insert(2, 3);
  p.insert(4, 5);
  p.insert(1, 2);
  p.insert(6, 7);
  p.insert(3, 4);

  p.Print();
}
