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

}

Map::~Map()
{
  for (int i = 0; i < _height; i++)
    delete[] _matrix[i];
  delete[] _matrix;
}


void Map::Reset()
{
  for(int i=0; i<_height; i++)
    for(int j=0; j<_width; j++)
      _matrix[i][j] = '~';
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
