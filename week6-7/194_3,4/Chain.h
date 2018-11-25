#pragma once
#include"ChainIterator.h"

template<class T>
class Chain
{	
	
	friend int compute(Chain<int> x);
	friend void copy1(Chain<int>x, int *y);
public:
	Chain() { first=0; }
	void Add(ChainNode<T>*x, ChainNode<T>*y)
	{
		if (x== 0)first = y;
		else x->link= y;
	}

private:
	ChainNode<T>* first;
};