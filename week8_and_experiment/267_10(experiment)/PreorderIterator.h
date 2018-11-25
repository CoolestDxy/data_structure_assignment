#pragma once
#include"TreeNode.h"
#include"Tree.h"
#include"LinkedStack.h"
template<class T>
class Tree;
template<class T>
class TreeNode;
template<class T>
class LinkedStack;
template<class T>
class PreorderIterator
{
public:
	PreorderIterator(Tree<T> t) { CurrentNode = t.root; }
	T Next()//ǰ�������������������һ�������ڵ㣬�ѵ������������������ʱ�����ɣ�����flag�����֣����õݹ鷽ʽ�����սڵ�
	{
		T temp = 0;
		if (!s.IsEmpty() || CurrentNode)
		{
			if (flag == 1)
			{
				if (CurrentNode != 0)
				{
					s.Push(CurrentNode);
					temp = CurrentNode->data;
					CurrentNode = CurrentNode->leftChild;
					flag = 1;//����������ʱflag=1
				}
				else
				{
					flag = 0;//������������flag=0
				}
			}
			if (flag == 0)//flag=0ʱ��������һ�����������ڼ����
			{
				CurrentNode = s.gettop();
				s.Pop();
				CurrentNode = CurrentNode->rightChild;
				if (CurrentNode != 0)
				{
					s.Push(CurrentNode);
					temp = CurrentNode->data;
					CurrentNode = CurrentNode->leftChild;
				}
				else temp = Next();//�˴����õݹ�����������������ʱ�����ڵĵ㣬ʹÿ��next��������
				flag = 1;
			}
		}
		return temp;
	}
	void preorder()
	{
		T a = Next();
		while (a)
		{
			cout << a;
			a = Next();
		}
	}
private:
	LinkedStack<TreeNode<T>*>s;
	TreeNode<T>*CurrentNode;
	int flag = 1;
};