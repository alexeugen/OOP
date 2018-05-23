#include <cstddef>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct vheap {
	int val;
	int pon;
};

class PQueue {
public:
	PQueue();
	PQueue(int i);
	~PQueue();
	void insert(int va, int p);
	void extract();
	size_t GetSize() const;
	void SetSize(int i);

	int GetMaxVal();
	int GetMaxPon();
	vheap *GetVheap() const;


	PQueue operator = (PQueue const &p2);
	PQueue operator + (PQueue const &p2);
	PQueue operator - (int i);  //Sterge pozitia i
	PQueue operator++ ();
	PQueue operator++ (int);
	PQueue operator-- ();
	PQueue operator-- (int);
	friend ostream & operator<<(ostream & stream, const PQueue & p2);
	friend istream & operator>>(istream & stream, PQueue & p2);

	void Print();

private: //FUNCTIONS
	void max_heapify(int i);
	void max_heap();

	//VARIABLES
	vheap *v;
	size_t n;
	size_t aloc; // memoria alocata

};
