#pragma once
#include<iostream>
#include"Node.h"
using namespace std;
template<class T>
class Node;
template<class T>
class LinkedStack
{
public:
	LinkedStack():top(0){}
	void Push(const T& x)
	{
		top = new Node<T>(x, top);
	}
	bool IsEmpty()
	{
		return top == 0;
	}
	void Pop()
	{
		if (IsEmpty())throw"Stack is empty ";
		Node<T>*del = top;
		top = top->link;
		delete del;
	}
	void print()
	{
		Node<T>*temp = top;
		while (temp!= 0)
		{
			cout << " " << temp->data << " ";
			temp = temp->link;
		}
		cout << endl;
	}
private:
	Node<T>* top;
};

