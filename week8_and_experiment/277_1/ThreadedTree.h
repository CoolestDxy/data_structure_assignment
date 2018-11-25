#pragma once
#include<iostream>
#include"ThreadedNode.h"
using namespace std;

class ThreadedTree
{
public:
	void Build()//构建一个二叉树
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
		InorderThreading(root);
	}
	void InorderThreading(ThreadedNode*temp)//中序线索化二叉树
	{
		if (temp == 0)
		{
			return;
		}
		InorderThreading(temp->leftChild);
		if (temp->leftChild == 0)
		{
			temp->LeftThread = 1;
			temp->leftChild = prev;
		}
		if (prev != 0 && prev->rightChild == 0)
		{
			prev->rightChild = temp;
			prev->RightThread = 1;
		}
		prev = temp;
		InorderThreading(temp->rightChild);
	}
	void Inorder()//中序遍历
	{
		ThreadedNode*Cur = root;
		while (Cur)
		{
			while (Cur->LeftThread == 0)
			{
				Cur = Cur->leftChild;
			}
			cout << Cur->data << " ";
			while (Cur&&Cur->RightThread == 1)
			{
				Cur = Cur->rightChild;
				if(Cur)
				cout << Cur->data << ' ';
			}
			if (Cur)
			Cur = Cur->rightChild;
		}
	}

	ThreadedNode*Next(ThreadedNode* Cur)//又来获取中序遍历的下一个节点
	{
		ThreadedNode*temp = Cur->rightChild;
		if (!Cur->RightThread)
			while (!temp->LeftThread)temp = temp->leftChild;
		Cur = temp;
		if (Cur == root)return 0;
		else return Cur;
	}
	void InsertLeft(ThreadedNode*l,ThreadedNode*s)//插入左节点，将l置于s的左节点
	{
		ThreadedNode*temp = s;
		while (temp->leftChild != 0)//将temp置于中序遍历的第一个节点
		{
			temp = temp->leftChild;
		}
		while (temp&&temp->rightChild!= s)//寻找下一个节点直至找到rightchild指向s的节点，将这个节点的rightchild指向插入的l节点
		{
			temp = Next(temp);
		}
		if(temp)
		temp->rightChild = l;
		l->leftChild = s->leftChild;
		l->LeftThread = s->LeftThread;
		l->rightChild = s;
		l->RightThread = 1;
		s->leftChild = l;
		s->LeftThread = 0;
	}
	
	void testinsert() { ThreadedNode*a = new ThreadedNode('^'); InsertLeft(a, root->leftChild); }//测试插入节点
private:
	ThreadedNode*root,*prev;
};