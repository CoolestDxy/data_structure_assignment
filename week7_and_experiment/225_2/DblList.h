#pragma once

#include<iostream>
#include"DblListNode.h"
using namespace std;

class DblList
{
public:
	DblList() { first = new DblListNode; }
	void Delete(DblListNode * x)
	{
		if (x == first)cerr << "Deletion of head node not permitted" << endl;
		else {
			x->llink->rlink = x->rlink;
			x->rlink->llink = x->llink;
			delete x;
		}
	}
	void Add(DblListNode*x)
	{
		DblListNode*temp = first->llink;
		first->llink = x;
		temp->rlink = x;
		x->llink = temp;
		x->rlink = first;
	}
	void Insert(DblListNode*p, DblListNode*x)
	{
		p->llink = x;
		p->rlink = x->rlink;
		x->rlink->llink = p;
		x->rlink = p;
	}
	void print()
	{
		DblListNode*l = first->rlink;
		if (first->rlink == first)
		{
			cout << "empty!" << endl;
		}
		else{
		while (l != first->llink)
		{
			cout << " " << l->data << " ";
			l = l->rlink;
		}
		cout << " " << l->data << " "<<endl;
		}
	}
	void Concatenate(DblList m)
	{
		DblListNode*temp = first->llink;
		temp->rlink = m.first->rlink;
		m.first->rlink->llink = temp;
		first->llink = m.first->llink;
		m.first->llink->rlink = first;
		m.first->llink = m.first->rlink = m.first;
		print();
		m.print();
	}
private:
	DblListNode* first;
};