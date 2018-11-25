#pragma once
#include"ChainIterator.h"
template<class T>
class ChainIterator;
template<class T>
class Chain;

template<class T>
class ChainNode
{
	friend void mycopy(ChainIterator<int> start, ChainIterator<int>end, int*y);
	friend int compute(Chain<int> x);
	friend class Chain<T>;
	friend class ChainIterator<T>;
	friend void copy1(Chain<int>x, int *y);
public:
	ChainNode(T x=0):data(x){}
private:
	T data;
	ChainNode<T>*link;
};

