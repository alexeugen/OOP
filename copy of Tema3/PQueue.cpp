#include "PQueue.h"

#include <iostream>
using namespace std;

PQueue::PQueue()
{
	v = (vheap*)malloc(sizeof(vheap) * 10);
	n = 1; // Pozitia pe care o sa pun prima valoare
	aloc = 10;
}

PQueue::PQueue(int i)
{
	v = (vheap*)malloc(sizeof(vheap) * 20);
	n = 11;
	for (int j = 1; j < n; j++)
	{
		v[j].pon = i;
		v[j].val = i;
	}
	n = 11; // Pozitia pe care o sa pun prima valoare
	aloc = 20;
}

PQueue::~PQueue()
{
	delete[] v;
}


void PQueue::max_heapify(int i)
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
		vheap aux = v[i];
		v[i] = v[max];
		v[max] = aux;
		max_heapify(max);
	}
}


void PQueue::max_heap()
{
	for (int i = n / 2; i >= 0; i--)
		max_heapify(i);
}

void PQueue::insert(int va, int p)
{
	if (n + 4 >= aloc)
	{
		v =(vheap*) realloc(v, sizeof(vheap) * (n + 10));
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
void PQueue::extract()
{

	v[1] = v[n - 1];
	n--;
	max_heapify(1);
}

void PQueue::Print()
{
	for (int i = 1; i<n; i++)
		cout << "(" << v[i].val << ", " << v[i].pon << ") ";
	cout << endl;
}

size_t PQueue::GetSize() const
{
	return n - 1;
}

void PQueue::SetSize(int i)
{
	n = i + 1;
}


int PQueue::GetMaxVal()
{
	int maxi = v[1].val;
	for (int i = 2; i < n; i++)
		if (v[i].val > maxi)
			maxi = v[i].val;
	return maxi;
}

int PQueue::GetMaxPon()
{
	return v[1].pon;
}

vheap *PQueue::GetVheap() const
{
	vheap *v2;
	v2 = (vheap*) malloc(sizeof(vheap)*n);
	for (int i = 1; i < n; i++)
		v2[i] = v[i];
	return v2;
}

PQueue PQueue::operator=(PQueue const & p2)
{
	PQueue *res = new PQueue();
	vheap *vh;
	vh = (vheap*)p2.GetVheap();
	for (int i = 1; i < p2.GetSize() + 1; i++)
		res->insert(vh[i].val, vh[i].pon);

	n = (int)p2.GetSize() + 1;
	for (int i = 1; i < p2.GetSize() + 1; i++)
	{
		if (n + 4 >= aloc)
		{
			v =(vheap*) realloc(v, sizeof(vheap) * (n + 10));
			aloc += 10;
		}
		v[i].val = vh[i].val;
		v[i].pon = vh[i].pon;
	}
		res->SetSize((int)p2.GetSize());
	n = (int)p2.GetSize() + 1;
	return *res;
}

PQueue PQueue::operator+(PQueue const & p2)
{
	PQueue *res = new PQueue();
	*res = *this;
	vheap *vh;
	vh = p2.GetVheap();
	for (int i = 1; i < p2.GetSize() + 1; i++)
		res->insert(vh[i].val, vh[i].pon);

	return *res;
}

PQueue PQueue::operator-(int i)
{
	PQueue *res = new PQueue();
	v[i] = v[n - 1];
	n--;
	max_heapify(i);
	*res = *this;
	return *res;
}

PQueue PQueue::operator++()
{
	for (int i = 0; i < n; i++)
		v[i].pon++;
	PQueue *res = new PQueue();
	*res = *this;
	return *res;
}

PQueue PQueue::operator++ (int)
{
	PQueue *res = new PQueue();
	*res = *this;
	++(*this);
	return *res;
}

PQueue PQueue::operator--()
{
	for (int i = 1; i < n ; i++)
	{
		v[i].pon--;
		if (v[i].pon <= 0)
		{
			v[i] = v[n - 1];
			n--;
			max_heapify(i);
		}
	}

	PQueue *res = new PQueue();
	*res = *this;
	return *res;
}

PQueue PQueue::operator--(int)
{
	PQueue *res = new PQueue();
	*res = *this;
	--(*this);
	return *res;
}


ostream & operator<<(ostream & stream, const PQueue & p2)
{
	for (int i = 1; i<p2.n; i++)
		stream << "(" << p2.v[i].val << ", " << p2.v[i].pon << ") ";
	stream << endl;
	return stream;
}

istream & operator>>(istream & stream, PQueue & p2)
{
	int x,y;
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
