#include "PQueue.h"
#include <iostream>

using namespace std;

int main()
{
	PQueue p;


	p.insert(2, 3);
	p.insert(4, 5);
	p.insert(5, 6);
	p.insert(1, 2);
	p.insert(6, 7);
	p.insert(3, 4);
	cout << "Valorile initiale" << endl;
	p.Print();
	cout << "Numarul de valori:" << endl;
	cout << p.GetSize() << endl;
	p.extract();
	cout << "Dupa ce o valoare este extrasa" << endl;
	p.Print();
	cout << "Numarul de valori:" << endl;
	cout << p.GetSize() << endl;
	p.extract();
	p.extract();
	cout << "Dupa ce inca doua valori sunt extrase" << endl;
	p.Print();
	cout << "Numarul de valori:" << endl;
	cout << p.GetSize() << endl;

	p.insert(11, 12);
	p.insert(17, 18);
	p.insert(15, 16);
	p.insert(7, 8);
	p.insert(33, 21);
	p.insert(8, 9);
	p.insert(45, 24);
	p.insert(9, 10);
	p.insert(66, 99);

	cout << "Inca 9 valori adaugate" << endl;
	p.Print();
	cout << "Numarul de valori:" << endl;
	cout << p.GetSize() << endl;
	cout << "Ponderea maxima" << endl;
	cout << p.GetMaxPon() << endl;
	cout << "Valoarea maxima" << endl;
	cout << p.GetMaxVal() << endl;


	cout << "Am creat o noua coada de prioritati" << endl;
	PQueue p2;
	PQueue p1;
	p2.insert(110, 110);
	p2.insert(230, 230);
	p2.insert(999, 999);
	p2.Print();

	cout << "Am copiat-o in prima" << endl;
	p1 = p;
	p = p2;
	p.Print();

	cout << "Iar asa ar arata adunate" << endl;
	p1 = p1 + p2;
	p1.Print();
	cout << "Numarul de valori:" << endl;
	cout << p1.GetSize() << endl;

	cout << "Iar daca am creste ponderea cu 1 folosind ++" << endl;
	p1++;
	p1.Print();
	cout << "Numarul de valori:" << endl;
	cout << p1.GetSize() << endl;

	cout << "Acum o scadem la loc cu --  " << endl;
	p1--;
	p1.Print();
	cout << "Numarul de valori:" << endl;
	cout << p1.GetSize() << endl;


	cout << "Scazuta de 3 ori cu --  (observam ca cele care ar fi devenit 0 dispar)" << endl;
	p1--;
	p1--;
	p1--;
	p1.Print();
	cout << "Numarul de valori:" << endl;
	cout << p1.GetSize() << endl;

	cout << "Constructor cu parametrii" << endl;
	PQueue p9(3);
	p9.Print();


	cout << "Supraincarcarea lui -  (scade pozitia i)" << endl;
	p9 = p9 - 3;
	p9.Print();
	cout<<p9;

//	cout << p9;

	PQueue p33;
	cin>>p33;
	cout<<p33;

}
