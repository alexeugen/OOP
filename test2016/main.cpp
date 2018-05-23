#include <iostream>

using namespace std;

#include "Ingredient.h"

int main()
{
  Ingredient lista[5] = { Ingredient("piept de pui", 15, 1, "kg"),
  Ingredient("sare",0.75, 10, "gram"), Ingredient("salam",1.5,5, "felii"),
  lista[2], Ingredient() }, i1("sunca", 3, 2, "felii");

  cout<<lista[2];

  lista[3] = lista[3] + 3;
  cout<<lista[3];
  lista[1]++;
  cout<<lista[1];
  lista[0] -= 2.5;
  cout<<lista[0];

  /*
Ingredient lista[5] = { Ingredient(”piept de pui”, 15, 1, ”kg”),
Ingredient(”sare”,0.75, 10, ”gram”), Ingredient(”salam”,1.5,5, ”felii”),
lista[2], Ingredient() }, i1(”sunca”, 3, 2, ”felii”);
cin >> lista[4]; // se citește un nou ingredient
lista[3] = lista[3] + 3; // se adaugă 3 felii de salam la ingredient
lista[1]++; // se adaugă un gram de sare la ingredient
lista[0]-=2.5; // se scade o valoare din pretul ingredientului
lista[2].del(); //ingredientul nu mai este disponibil
for (int i=0; i<5; i++) cout<<”Ingredient: “<<lista[i]<<endl;
Pizza p1 (”Rustica”, lista, 4, false);	// se crează un sortiment nou de pizza
Pizza p2 = p1, p3; // se crează două sortimente noi de pizza,
dintre care unul cu aceleași ingrediente ca pizza p1
p2 = p2 – lista[2]; // se scoate ingredientul respectiv din rețeta
sortimentului
p3 = p2 + i1;	// se stabilește rețeta pizzei p3 din ingredientele
 pizzei p2 la care se adaugă ingredientul i1
p3.nume(”Prosciuto”); // este schimbată denumirea pizzei p3
cout<<”Pizza ”<<p1.nume()<<” ”<<p1.pret()<<” lei”<<endl;
cout<<”Pizza ”<<p2.nume()<<” ”<<p2.pret()<<” lei”<<endl;
cout<<”Pizza ”<<p3.nume()<<” ”<<p3.pret()<<” lei”;
*/
}
