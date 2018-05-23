#pragma once
#include<iostream>
using namespace std;
#include "interfata.h"

class Pizza : public interfata
{
protected:
	Pizza **p;
	int pr;
	
	//preturi
		int manopera = 3, aluat = 2, sos = 1, mozzarella = 3, sunca = 2, rosii = 2,
			masline = 2, ardei = 2, oregano = 2, pui = 4, ciuperci = 3, salam = 3, 
			ou = 2, cabanos = 3, babic = 3, porumb = 2, ceapa = 2;

public:
	Pizza() 
	{
		p = new Pizza*[0];
		pr = 0;
	}
	~Pizza() {};

	int pretFinal(int optiune);
	
	//int online();
};


int Pizza :: pretFinal(int optiune)
{
	switch (optiune)
	{
	case 1:
		pr = manopera + aluat + sos + mozzarella + sunca + rosii + masline + ardei + oregano;
		break;

	case 2:
		pr = manopera + aluat + mozzarella + sunca + oregano;
		break;

	case 3:
		pr = manopera + aluat + sos + mozzarella + sunca + ardei + masline + babic + salam + oregano;
		break;

	case 4:
		pr = manopera + aluat + sos + mozzarella + sunca + rosii + ardei + ciuperci + oregano + cabanos;
		break;

	case 5:
		pr = manopera + aluat + sos + mozzarella + cabanos + ou + ardei + oregano + porumb;
		break;

	case 6:
		pr = manopera + aluat + sos + mozzarella + pui + ciuperci + oregano;
		break;

	case 7:
		pr = manopera + aluat + sos + mozzarella + ciuperci + ceapa + masline + oregano;
		break;

	case 8:
		pr = manopera + aluat + sos + rosii + ardei + masline + ceapa;
		break;

	case 9:
		pr = manopera + aluat + sos + rosii + oregano + porumb + ciuperci;
		break;

	case 10:
		pr = manopera + aluat + sos + ciuperci + ceapa + porumb + ardei + oregano;

	}

	return pr;


}
