#include <iostream>
#include "Print.h"

using namespace std;

class Map{
public:
  friend class Agent1;
  Map(int width, int height);
  ~Map();

  void Display();


private:

	Print print;
  char **_matrix;
  int _width;
  int _height;

};
