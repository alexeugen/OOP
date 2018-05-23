#pragma once
#include<iostream>
using namespace std;
#include "Pizza.h"


class Meniu : public Pizza
{
	Pizza *p;
	int nr_pizza, nr_pizza_veg;
	int finalprice;

public:
	Meniu()
	{
		nr_pizza = 0;
		nr_pizza_veg = 0;
	}
	~Meniu() {};
	void addPizza();
	void addPizzaVeg();
	int afisare_meniu();
	//void operator += (const Meniu &m,int optiune);
};
void Meniu :: addPizza() {

	nr_pizza = nr_pizza + 1;
}

void Meniu::addPizzaVeg() {

	nr_pizza_veg = nr_pizza_veg + 1;
}
/*
void  Meniu::operator += (const Meniu &m, int optiune)
{
	if (optiune > 0 && optiune < 7)
		m->addPizza();
	if (optiune == 7 || optiune == 8 || optiune == 9 || optiune == 10)
		m->addPizzaVeg();
}
*/

	int Meniu::afisare_meniu()
	{
	int optiune;
	cout << "Alegeti una dintre optiuni:" << endl;
	do {
		cout << "***** MENIU *****" << endl << endl;
		cout << "1.Pizza Casei...............................500 g" << endl;
		cout << "2.Pizza Capriciosa .........................350 g" << endl;
		cout << "3.Pizza Suprema ............................450 g" << endl;
		cout << "4.Pizza Quattro Stagione ...................380 g" << endl;
		cout << "5.Pizza Mexicana ...........................380 g" << endl;
		cout << "6.Pizza Chicken ............................450 g" << endl;
		cout << "7.Pizza Special (veg).......................380 g" << endl;
		cout << "8.Pizza Mediteraneana (veg).................350 g" << endl;
		cout << "9.Pizza Fresh (veg).........................420 g" << endl;
		cout << "10.Pizza Veggie (veg).......................380 g" << endl;
		cout << endl;
		cout << "0. Exit";
		cout << "Alegeti un produs: ";
		cin >> optiune;
		
		switch (optiune)
		{
			
		case 1:
			 finalprice = p->pretFinal(1);
			nr_pizza++;
			break;

		case 2:
			 finalprice = p->pretFinal(2);
			nr_pizza++;
			break;

		case 3:
			 finalprice = p->pretFinal(3);
			nr_pizza++;
			break;

		case 4:
			 finalprice = p->pretFinal(4);
			nr_pizza++;
			break;

		case 5:
			 finalprice = p->pretFinal(5);
			nr_pizza++;
			break;

		case 6:
			 finalprice = p->pretFinal(6);
			 nr_pizza++;
			break;

		case 7:
			 finalprice = p->pretFinal(7);
			nr_pizza_veg++;
			break;

		case 8:
			 finalprice = p->pretFinal(8);
			nr_pizza_veg++;
			break;

		case 9:
			 finalprice = p->pretFinal(9);
			nr_pizza_veg++;
			break;

		case 10:
			 finalprice = p->pretFinal(10);
			nr_pizza_veg++;
			break;

		case 0:
			cout << "Multumim ca ati comandat de la noi!";
			break;
		default:
			cout << "Eroare! Produsul nu este in meniu!";
			break;
		}

		cout << "Pret total pentru comanda dvs.: ";

	} while (optiune != 0);

	return finalprice;
}


