#ifndef _ITEM_H
#define _ITEM_H

class Item{
public:
  int GetLin();
  int GetCol();
  char GetSymbol();

protected:
  int _lin, _col;
  char* _type;
  char _symbol;
};

#endif
