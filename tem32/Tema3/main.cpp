#include "PQueue.h"
#include <iostream>

using namespace std;

int main()
{
	PQueue<float> p;


	p.insert(2.3, 3);
	p.insert(4.2, 5);
	p.insert(2.4, 2);
	p.insert(2.5, 2);
	p.insert(2.1, 2);
	p.insert(2.4, 4);
	cout << "Valorile initiale" << endl;
	p.Print();


}
