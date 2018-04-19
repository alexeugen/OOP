#include "Map.h"

Map::Map(int width, int height)
{

  _matrix = new char *[height];
  for (int i = 0; i < height; i++)
    _matrix[i] = new char[width];

  _height = height;
  _width = width;

  for(int i=0; i<_height; i++)
    for(int j=0; j<_width; j++)
      _matrix[i][j] = '~';

  _matrix[0][3] = '@';
  _matrix[0][5] = '#';
  _matrix[5][5] = '$';

}

Map::~Map()
{
  for (int i = 0; i < _height; i++)
    delete[] _matrix[i];
  delete[] _matrix;
}

void Map::Display()
{
  for(int i=0; i<_height; i++)
  {
    for(int j=0; j<_width; j++)
    {
    	cout<<" ";
    	print << _matrix[i][j];
    	cout<<" ";
    }
    cout<<endl;
  }
}
