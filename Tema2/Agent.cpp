#include "Agent.h"

Agent::Agent()
{

}

Agent::Agent(int pozx, int pozy)
{
  _poz_x = pozx;
  _poz_y = pozy;
}


int Agent::CheckShield()
{
  return _shield;
}

void Agent::SetShield()
{
  _shield = 1;
}

void Agent::ClearShield()
{
  _shield = 0;
}

void Agent::SetExtended()
{
  _extended = 1;
}
void Agent::SetBrainy()
{
  _brainy = 1;
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
