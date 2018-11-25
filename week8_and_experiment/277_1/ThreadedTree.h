#pragma once
#include<iostream>
#include"ThreadedNode.h"
using namespace std;

class ThreadedTree
{
public:
	void Build()//����һ��������
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
	void InorderThreading(ThreadedNode*temp)//����������������
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
	void Inorder()//�������
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

	ThreadedNode*Next(ThreadedNode* Cur)//������ȡ�����������һ���ڵ�
	{
		ThreadedNode*temp = Cur->rightChild;
		if (!Cur->RightThread)
			while (!temp->LeftThread)temp = temp->leftChild;
		Cur = temp;
		if (Cur == root)return 0;
		else return Cur;
	}
	void InsertLeft(ThreadedNode*l,ThreadedNode*s)//������ڵ㣬��l����s����ڵ�
	{
		ThreadedNode*temp = s;
		while (temp->leftChild != 0)//��temp������������ĵ�һ���ڵ�
		{
			temp = temp->leftChild;
		}
		while (temp&&temp->rightChild!= s)//Ѱ����һ���ڵ�ֱ���ҵ�rightchildָ��s�Ľڵ㣬������ڵ��rightchildָ������l�ڵ�
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
	
	void testinsert() { ThreadedNode*a = new ThreadedNode('^'); InsertLeft(a, root->leftChild); }//���Բ���ڵ�
private:
	ThreadedNode*root,*prev;
};