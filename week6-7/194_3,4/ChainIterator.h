#pragma once
#include"ChainNode.h"
template<class T>
class ChainIterator
{
	friend void mycopy(ChainIterator<int> start, ChainIterator<int>end, int*y);
	friend int compute(Chain<int> x);
	friend void copy1(Chain<int>x, int *y);
public:
	ChainIterator(ChainNode<T>*startNode = 0) { current = startNode; }
	T& operator*()const { return current->data; }
	T* operator->()const { return &current->data; }
	ChainIterator& operator ++() { current = current->link; return *this; }
	ChainIterator operator ++(int) {
		ChainIterator old = *this;
		current = current->link;
		return old;
	}
	bool operator!=(const ChainIterator right)const
	{
		return current != right.current;
	}
	bool operator==(const ChainIterator right)const
	{
		return current == right.current;
	}

private:
	ChainNode<T>* current;
};

