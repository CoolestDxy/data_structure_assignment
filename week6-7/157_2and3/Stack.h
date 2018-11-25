#pragma once
#include <iostream>
using namespace std;

struct items {
	int x, y, dir;
	items(int w=0, int e=0, int r=0)
	{
		x = w; y = e; dir = r;
	}
friend	ostream& operator<<(ostream&os, items&item)
	{
		return os << item.x << "," << item.y << "," << item.dir;
	}
items& operator=(items*t) {
	x = t->x; y = t->y; dir = t->dir;
}
};

template<class T>

class Stack
{
	friend ostream& operator <<(ostream&os, Stack<T> &s) {
		os << "top= " << s.top << endl;
		for (int i = 0; i <= s.top; i++)
			os << i << ":" << s.stack[i] << endl;
		return os;
	}
public:
	Stack(int i=100);
	~Stack();
	void Add(items);
	items* Delete(items&);
	void Delete();
	bool IsEmpty();
	
private: 
	items *stack;
	int top;
};

