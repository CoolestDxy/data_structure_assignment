#include "LinkedList.h"
#include<iostream>
using namespace std;


LinkedList::LinkedList() 
{
	first = 0;
}


LinkedList::~LinkedList()
{
}

void LinkedList::Add(Node*x,Node*y)
{
	if (x == 0)first = y;
	else x->link = y;
}

void LinkedList::Delete(Node*x)
{
	if (x == first) {
		first = x->link;
		delete x;
	}
	else {
		Node*temp = first;
		while (temp->link != x)
		{
			temp = temp->link;
		}
		temp->link = x->link;
		delete x;
	}
}

int LinkedList::length()
{
	int l=0; Node *temp = first;
	while (temp != 0)
	{
		temp = temp->link;
		l++;
	}
	return l;
}

void LinkedList::print()
{
	Node*temp = first;
	while (temp != 0)
	{
		cout << " " << temp->data << " ";
		temp = temp->link;
	}
	cout << endl;
}

void LinkedList::trav(travers& x)
{
	Node*temp = first,*t=0;
	while (temp != x.r)
	{
		t = temp->link;
		if (temp == first)
		{
			first->link = first;
		}
		else
		{
			temp->link = first->link;
			first->link = temp;
		}
		temp = t;
	}
	first->link = 0;
}

void LinkedList::travl(travers&x, int n)
{
	Node*temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp = x.l;
		x.l = x.l->link;
		temp->link = x.r;
		x.r = temp;
		if (x.r == first)return;
	}

}

void LinkedList::travr(travers&x, int n)
{
	Node*temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp = x.r->link;
		x.r->link = x.l;
		x.l = x.r;
		x.r = temp;
		if (x.r->link==0)return;
	}

}

void LinkedList::print(travers x)
{
	cout << "from l: ";
	Node*temp = x.l;
	while (temp != 0)
	{
		cout << " " << temp->data << " ";
		temp = temp->link;
	}
	cout << endl << "from r: ";
	temp = x.r;
	while (temp != 0)
	{
		cout << " " << temp->data << " ";
		temp = temp->link;
	}
	cout << endl;
}