#pragma once
#include<stack>
#include<iostream>
#include"Node.h"
using namespace std;
class Node;
class Tree
{
public:
	void build1()
	{
		Node* a1 = new Node(1);
		Node* a2 = new Node(2);
		Node* a3 = new Node(3);
		Node* a4 = new Node(4);
		Node* a5 = new Node(5);
		a1->lChild = a2;
		a1->rChild = a3;
		a2->rChild = a4;
		a3->lChild = a5;
		root = a1;
	}
	void build2()
	{
		Node* a1 = new Node(100);
		Node* a2 = new Node(200);
		Node* a3 = new Node(300);
		Node* a4 = new Node(400);
		Node* a5 = new Node(500);
		a1->lChild = a3;
		a1->rChild = a2;
		a2->lChild = a4;
		a3->lChild = a5;
		root = a1;
	}
	void preorder()
	{
		Node*Cur=root;
		stack<Node*>s;
		while (!s.empty() || Cur)
		{
			while (Cur)
			{
				cout << Cur->data<<' ';
				s.push(Cur);
				Cur = Cur->lChild;
			}
			if (!s.empty())
			{
				Cur = s.top();
				s.pop();
				Cur = Cur->rChild;
			}
		}
	}
private:
	Node*root;
};