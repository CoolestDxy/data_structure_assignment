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
		if (Cur->lChild==0)//左子树为零
		{
			if (last == 0) //根节点
			{
				root = Cur->rChild;
				delete Cur;
				Cur = 0;
				return true;
			}
			else if (Cur->data->key < last->data->key)//删除节点为左节点
			{
				last->lChild = Cur->rChild;
				delete Cur;
				Cur = 0;
				return true;
			}
			else //删除节点为右节点
			{
				last->rChild = Cur->rChild;
				delete Cur;
				Cur = 0;
				return true;
			}
		}
		else if (Cur->rChild == 0)//右子树为零
		{
			if (last == 0)//根节点
			{
				root = Cur->lChild;
				delete Cur;
				Cur = 0;
				return true;
			}
			else if (Cur->data->key < last->data->key)//删除节点为左节点
			{
				last->lChild = Cur->lChild;
				delete Cur;
				Cur = 0;
				return true;
			}
			else //删除节点为右节点
			{
				last->rChild = Cur->lChild;
				delete Cur;
				Cur = 0;
				return true;
			}
		}
		else //左右子树均不为零
		{
			if (Cur->rChild->lChild == 0)//右子树无左节点
			{
				Cur->rChild->lChild = Cur->lChild;
				if (Cur->data->key < last->data->key)//删除节点为左节点
				{
					last->lChild = Cur->rChild;
					delete Cur;
					Cur = 0;
					return true;
				}
				else //删除节点为右节点
				{
					last->rChild = Cur->rChild;
					delete Cur;
					Cur = 0;
					return true;
				}
			}
			else//右子树有左节点,寻找删除节点后继节点与其替换，把原后继节点删除
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