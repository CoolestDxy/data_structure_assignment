#pragma once
#include"Node.h"
struct travers {
	Node*l, *r;
	travers(Node*x, Node*y)
	{
		l = x; r = y;
	}
};
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void Add(Node*x,Node*y);
	void Delete(Node*x);//delete node
	int length();
	void print();
	void trav(travers& x);//travers
	void travl(travers&x, int n);//move left
	void travr(travers&x, int n);//move right
	void print(travers x);
private:
	Node*first;
};

