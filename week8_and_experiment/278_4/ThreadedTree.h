#pragma once
#include<iostream>
#include"ThreadedNode.h"
using namespace std;

class ThreadedTree
{
public :
	void Build()
	{
		ThreadedNode*a = new ThreadedNode('+');
		ThreadedNode*b = new ThreadedNode('*');
		ThreadedNode*c = new ThreadedNode('-');
		ThreadedNode*e = new ThreadedNode('/');
		ThreadedNode*f = new ThreadedNode('A');
		ThreadedNode*g = new ThreadedNode('B');
		a->addleft(b);
		a->addright(c);
		b->addleft(e);
		b->addright(f);
		c->addright(g);
		root = a;
		prev = 0;
		preorderThreading(root);
	}
	void preorderThreading(ThreadedNode*temp)//递归方式线索化，复杂度O(n)
	{

		if (temp == nullptr)
		{
			return;
		}
		if (temp->leftChild == 0)
		{
			temp->leftChild = prev;
			temp->LeftThread = 1;
		}
		if (prev != 0 && prev->rightChild == 0)
		{
			prev->rightChild = temp;
			prev->RightThread = 1;
		}
		prev = temp;
		if (temp->LeftThread==0)
		{
			preorderThreading(temp->leftChild);

		}
		if (temp->RightThread==0)
		{
			preorderThreading(temp->rightChild); 
		}
			
	}
	void preorder()//前序遍历不需要栈
	{
		ThreadedNode*Cur = root;
		while (Cur != 0)
		{
			if (root == 0)
				return;
			while (Cur->leftChild != 0 && Cur->LeftThread==0)
			{
				cout << Cur->data << ' ';
				Cur = Cur->leftChild;
			}
			cout << Cur->data << ' ';
			if (Cur->LeftThread==1)
			{
				Cur = Cur->rightChild;
			}
			while (Cur != 0)
			{
				if (Cur->leftChild != 0 && Cur->LeftThread == 0)
				{
					break;
				}
				cout << Cur->data << ' ';
				Cur = Cur->rightChild;
			}
		}
	}

private:
	ThreadedNode*root,*prev;
};