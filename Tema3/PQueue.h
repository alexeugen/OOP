#include <cstddef>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct vheap {
	T val;
	int pon;
};


template <typename T>
class PQueue;


template <typename T>
ostream & operator<<(ostream & stream, const PQueue<T> & p2)
{
	for (int i = 1; i<p2.n; i++)
		stream << "(" << p2.v[i].val << ", " << p2.v[i].pon << ") ";
	stream << endl;
	return stream;
}

template <typename T>
istream & operator>>(istream & stream, PQueue <T> & p2)
{
	T x;
	int y;
	int nc;

	stream>>nc;
	nc++;

	p2.aloc = 10;
	for (int i = 1; i<nc; i++)
	{
		stream >> x >> y;
		p2.insert(x,y);
	}

	return stream;
}


/****************     CLASA    ****************/

template <typename T>
class PQueue {
public:
	PQueue();
	PQueue(int i);
	~PQueue();
	void insert(T va, int p);
	void extract();
	size_t GetSize() const;
	void SetSize(int i);

	int GetMaxVal();
	int GetMaxPon();
	vheap<T> *GetVheap() const;


	PQueue operator = (PQueue const &p2);
	PQueue operator + (PQueue const &p2);
	PQueue operator - (int i);  //Sterge pozitia i
	PQueue operator++ ();
	PQueue operator++ (int);
	PQueue operator-- ();
	PQueue operator-- (int);
	friend ostream & operator<< <T> (ostream & stream, const PQueue & p2);
	friend istream & operator>> <T> (istream & stream, PQueue & p2);

	void Print();

private: //FUNCTIONS
	void max_heapify(int i);
	void max_heap();

	//VARIABLES
	vheap<T> *v;
	size_t n;
	size_t aloc; // memoria alocata

};



/********************                   IMPLEMENTARI                    *************/

template <typename T>
PQueue<T>::PQueue()
{
	v = new vheap<T>[100];
	n = 1; // Pozitia pe care o sa pun prima valoare
	aloc = 100;
}

template <typename T>
PQueue<T>::PQueue(int i)
{
	v = (vheap<T>*)malloc(sizeof(vheap<T>) * 20);
	n = 11;
	for (int j = 1; j < n; j++)
	{
		v[j].pon = i;
		v[j].val = i;
	}
	n = 11; // Pozitia pe care o sa pun prima valoare
	aloc = 20;
}

template <typename T>
PQueue<T>::~PQueue()
{

	delete[] v;
}

template <typename T>
void PQueue<T>::max_heapify(int i)
{
	int l = 2 * i;
	int r = 2 * i + 1;
	int max;
	int aux;

	if (l <= n && v[l].pon > v[i].pon)
		max = l;
	else
		max = i;
	if (r<n && v[r].pon > v[max].pon)
		max = r;
	if (max != i)
	{
		vheap<T> aux = v[i];
		v[i] = v[max];
		v[max] = aux;
	}
}

template <typename T>
void PQueue<T>::max_heap()
{
	for (int i = n / 2; i >= 0; i--)
		max_heapify(i);
}

template <typename T>
void PQueue<T>::insert(T va, int p)
{
	if (n + 4 >= aloc)
	{
		v =(vheap<T>*) realloc(v, sizeof(vheap<T>) * (n + 10));
		aloc += 10;
	}

	v[n].val = va;
	v[n].pon = p;
	int i = n;
	n++;
	while (i / 2 != 0 && v[i / 2].pon < v[i].pon)
	{
		max_heapify(i / 2);
		i = i / 2;
	}
}

template <typename T>
void PQueue<T>::extract()
{

	v[1] = v[n - 1];
	n--;
	max_heapify(1);
}

template <typename T>
void PQueue<T>::Print()
{
	for (int i = 1; i<n; i++)
		cout << "(" << v[i].val << ", " << v[i].pon << ") ";
	cout << endl;
}

template <typename T>
size_t PQueue<T>::GetSize() const
{
	return n - 1;
}

template <typename T>
void PQueue<T>::SetSize(int i)
{
	n = i + 1;
}

template <typename T>
int PQueue<T>::GetMaxVal()
{
	T maxi = v[1].val;
	for (int i = 2; i < n; i++)
		if (v[i].val > maxi)
			maxi = v[i].val;
	return maxi;
}

template <typename T>
int PQueue<T>::GetMaxPon()
{
	return v[1].pon;
}

template <typename T>
vheap<T> *PQueue<T>::GetVheap() const
{
	vheap<T> *v2;
	v2 = (vheap<T>*) malloc(sizeof(vheap<T>)*n);
	for (int i = 1; i < n; i++)
		v2[i] = v[i];
	return v2;
}

template <typename T>
PQueue<T> PQueue<T>::operator=(PQueue const & p2)
{
	PQueue *res = new PQueue();
	vheap<T> *vh;
	vh = (vheap<T>*)p2.GetVheap();
	for (int i = 1; i < p2.GetSize() + 1; i++)
		res->insert(vh[i].val, vh[i].pon);

	n = (int)p2.GetSize() + 1;
	for (int i = 1; i < p2.GetSize() + 1; i++)
	{
		if (n + 4 >= aloc)
		{
			v =(vheap<T>*) realloc(v, sizeof(vheap<T>) * (n + 10));
			aloc += 10;
		}
		v[i].val = vh[i].val;
		v[i].pon = vh[i].pon;
	}
		res->SetSize((int)p2.GetSize());
	n = (int)p2.GetSize() + 1;
	return *res;
}

template <typename T>
PQueue<T> PQueue<T>::operator+(PQueue const & p2)
{
	PQueue *res = new PQueue();
	*res = *this;
	vheap<T> *vh;
	vh = p2.GetVheap();
	for (int i = 1; i < p2.GetSize() + 1; i++)
		res->insert(vh[i].val, vh[i].pon);

	return *res;
}

template <typename T>
PQueue<T> PQueue<T>::operator-(int i)
{
	PQueue *res = new PQueue();
	v[i] = v[n - 1];
	n--;
	max_heapify(i);
	*res = *this;
	return *res;
}

template <typename T>
PQueue<T> PQueue<T>::operator++()
{
	for (int i = 0; i < n; i++)
		v[i].pon++;
	PQueue *res = new PQueue();
	*res = *this;
	return *res;
}

template <typename T>
PQueue<T> PQueue<T>::operator++ (int)
{
	PQueue *res = new PQueue();
	*res = *this;
	++(*this);
	return *res;
}

template <typename T>
PQueue<T> PQueue<T>::operator--()
{
	for (int i = 1; i < n ; i++)
	{
		v[i].pon--;
		if (v[i].pon <= 0)
		{
			v[i] = v[n - 1];
			n--;
			v[i].pon--;
			max_heapify(i);
		}
	}

	PQueue *res = new PQueue();
	*res = *this;
	return *res;
}

template <typename T>
PQueue<T> PQueue<T>::operator--(int)
{
	PQueue *res = new PQueue();
	*res = *this;
	--(*this);
	return *res;
}
