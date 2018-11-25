#pragma once
#include<stack>
#include"BstNode.h"
using namespace std;
template<class T>
class Bst
{
public:
	Bst() { root = 0;  }
	bool Insert(Dictionary<T>x)
	{
		BstNode<T>*p = root;
		BstNode<T>*q = 0;
		while (p)
		{
			q = p;
			if (x.key == p->data->key)return false;
			if (x.key < p->data->key)p = p->lChild;
			else p = p->rChild;
		}
		p = new BstNode<T>;
		p->lChild = p->rChild = 0;
		p->data->d = x.d;
		p->data->key=x.key;
		if (!root)root = p;
		else if (x.key < q->data->key)q->lChild = p;
		else q->rChild = p;
		return true;
	}
	bool Delete(int k)//O(n)
	{
		BstNode<T>*Cur = root, *last = 0;
		while (Cur->data->key != k)
		{
			last = Cur;
			if (k < Cur->data->key)Cur = Cur->lChild;
			else Cur = Cur->rChild;
		}
		if (!Cur)return false;
		if (Cur->lChild==0)//������Ϊ��
		{
			if (last == 0) //���ڵ�
			{
				root = Cur->rChild;
				delete Cur;
				Cur = 0;
				return true;
			}
			else if (Cur->data->key < last->data->key)//ɾ���ڵ�Ϊ��ڵ�
			{
				last->lChild = Cur->rChild;
				delete Cur;
				Cur = 0;
				return true;
			}
			else //ɾ���ڵ�Ϊ�ҽڵ�
			{
				last->rChild = Cur->rChild;
				delete Cur;
				Cur = 0;
				return true;
			}
		}
		else if (Cur->rChild == 0)//������Ϊ��
		{
			if (last == 0)//���ڵ�
			{
				root = Cur->lChild;
				delete Cur;
				Cur = 0;
				return true;
			}
			else if (Cur->data->key < last->data->key)//ɾ���ڵ�Ϊ��ڵ�
			{
				last->lChild = Cur->lChild;
				delete Cur;
				Cur = 0;
				return true;
			}
			else //ɾ���ڵ�Ϊ�ҽڵ�
			{
				last->rChild = Cur->lChild;
				delete Cur;
				Cur = 0;
				return true;
			}
		}
		else //������������Ϊ��
		{
			if (Cur->rChild->lChild == 0)//����������ڵ�
			{
				Cur->rChild->lChild = Cur->lChild;
				if (Cur->data->key < last->data->key)//ɾ���ڵ�Ϊ��ڵ�
				{
					last->lChild = Cur->rChild;
					delete Cur;
					Cur = 0;
					return true;
				}
				else //ɾ���ڵ�Ϊ�ҽڵ�
				{
					last->rChild = Cur->rChild;
					delete Cur;
					Cur = 0;
					return true;
				}
			}
			else//����������ڵ�,Ѱ��ɾ���ڵ��̽ڵ������滻����ԭ��̽ڵ�ɾ��
			{
				BstNode<T>*temp = Cur,*parent=last;
				while (Cur->lChild != 0)
				{
					last = Cur;
					Cur = Cur->lChild;
				}
				temp->data = Cur->data;
				last->lChild = Cur->rChild;
				delete Cur;
				Cur = 0;
				return true;
			}
		}
	}
	void inorderprint()
	{
		BstNode<T>*Cur = root;
		stack<BstNode<T>*>s;
		while (!s.empty()||Cur)
		{
			while (Cur != 0)
			{
				s.push(Cur);
				Cur = Cur->lChild;
			}
			if (!s.empty())
			{
				Cur = s.top();
				cout << Cur->data->key<<' ';
				s.pop();
				Cur = Cur->rChild;
			}
		}
	}
	int findheight()
	{
		BstNode<T>*Cur = root;
		stack<BstNode<T>*>s;
		int h = 0,height=0;
		while (!s.empty() || Cur)
		{
			while (Cur != 0)
			{
				s.push(Cur);
				h++;
				Cur = Cur->lChild;
			}
			if (h > height)height = h;
			if (!s.empty())
			{
				Cur = s.top();
				s.pop();
				h--;
				Cur = Cur->rChild;
			}
		}
		return height;
	}
private:
	BstNode<T>*root;
};