#include "PQueue.h"

#include <iostream>
using namespace std;

PQueue::PQueue()
{
  v = new vheap[10];
  n = 0;
}

PQueue::~PQueue()
{

}


void PQueue::max_heapify(int i)
{
	int l = 2*i;
	int r = 2*i + 1;
	int max;
	int aux;

	if(l<n && v[l].pon > v[i].pon)
		max = l;
	else
		max = i;
	if(r<n && v[r].pon > v[max].pon)
		max = r;
	if(max != i)
	{
		vheap aux = v[i];
		v[i] = v[max];
		v[max] = aux;
		max_heapify(max);
	}
}


void PQueue::max_heap()
{
	for(int i = (n-1)/2; i>=0; i--)
		max_heapify(i);
}

void PQueue::insert(int va, int p)
{
	v[n].val = va;
	v[n].pon = p;
	int i = n;
	n++;
	while(i/2 != 0 && v[i/2].pon < v[i].pon)
	{
		max_heapify(i/2);
		i = i/2;
	}
}

void PQueue::extract()
{

	v[0] = v[n-1];
	n--;
	max_heapify(0);
}

void PQueue::Print()
{
  for(int i = 0; i<n; i++)
  cout<<v[i].val<<" ";
}
