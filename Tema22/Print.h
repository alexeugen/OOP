#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Print
{
public:
	Print()
	{


	}
	Print operator << (char c)
	{
		if(c == '~')
			printf("%c", c);
		else
		{
			printf("\033[1;31m%c\033[0m", c);
		}
	}
};
