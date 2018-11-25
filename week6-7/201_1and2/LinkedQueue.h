#pragma once
#include<iostream>
#include"Node.h"
using namespace std;
template<class T>
class Node;
template<class T>
class LinkedQueue
{
public:
	LinkedQueue():front(0),rear(0){}
	bool IsEmpty() {
		return front == 0&&rear==0;
	}
	void Push(const T& x)
	{
		if (IsEmpty())front = rear = new Node<T>(x, 0);
		else rear = rear->link = new Node<T>(x, 0);
	}
	void Pop()
	{
		if (IsEmpty())throw"Queue is empty";
		Node<T>* del=front;
		front = front->link;
		delete del;
	}
	void print()
	{
		Node<T>* temp = front;
		while (temp != rear)
		{
			cout << " " << temp->data << " ";
			temp = temp->link;
		}
		cout << " "<<temp->data << endl;
	}
private:
	Node<T> *front, *rear;
};