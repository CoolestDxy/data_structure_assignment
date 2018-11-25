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
	LinkedStack() { top = new Node<T>; top->link = 0; }
	void Push(const T& x)
	{
		Node<T>*temp = new Node<T>;
		temp->data = x;
		temp->link = top->link;
		top->link = temp;
	}
	bool IsEmpty()
	{
		return top->link == 0;
	}
	T& gettop()
	{
		return top->link->data;
	}
	T& Pop()
	{
		if (IsEmpty())throw"Stack is empty ";
		Node<T>*del = top->link;
		T temp = del->data;
		top->link = del->link;
		delete del;
		return temp;
	}
	void print()
	{
		Node<T>*temp = top;
		while (temp != 0)
		{
			cout << " " << temp->data << " ";
			temp = temp->link;
		}
		cout << endl;
	}
private:
	Node<T>* top;
};
