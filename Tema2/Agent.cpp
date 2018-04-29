#include "Agent.h"

char Agent::GetSymbol()
{
  return _symbol;
}

int Agent::GetLin()
{
  return _poz_x;
}
int Agent::GetCol()
{
  return _poz_y;
}


void Agent::reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}

char* Agent::my_itoa(int num)  //itoa code was shamefully coppied from geeksforgeeks
{                                         // and a little modified
    char *str = new char [20];
    int i = 0;
    bool isNegative = false;

    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (num < 0)
    {
        isNegative = true;
        num = -num;
    }

    while (num != 0)
    {
        int rem = num % 10;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/10;
    }


    if (isNegative)
        str[i++] = '-';

    str[i] = '\0';


    reverse(str, i);

    return str;
}
