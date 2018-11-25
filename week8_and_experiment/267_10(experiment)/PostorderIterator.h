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
class PostorderIterator
{
public:
	PostorderIterator(Tree<T> t) {
		CurrentNode = t.root;
		while (CurrentNode != 0)
		{
			s.Push(CurrentNode);
			CurrentNode = CurrentNode->leftChild;
		}
		CurrentNode = s.gettop();
		LastNode = 0;
	}
	T Next()//�����������Ҫ�жϵ�ǰ�ڵ���ӽڵ��Ƿ񶼷�����ɣ����¼��һ�η��ʵĽڵ���ʷ��
	{
		if (!s.IsEmpty()) {
			T temp;
			while (CurrentNode->rightChild != 0 && CurrentNode->rightChild != LastNode)//�ӽڵ���û���ʵ������ѭ���������ӽڵ������������
			{
				CurrentNode = CurrentNode->rightChild;
				while (CurrentNode != 0)
				{
					s.Push(CurrentNode);
					CurrentNode = CurrentNode->leftChild;
				}
				CurrentNode = s.gettop();
			}
			CurrentNode = s.gettop();//��ȡ��Ҫ������ӽڵ�
			s.Pop();
			temp = CurrentNode->data;
			LastNode = CurrentNode;
			if (!s.IsEmpty())
				CurrentNode = s.gettop();
			return temp;
		}
		else return 0;
	}
	void postorder()
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
	TreeNode<T>*CurrentNode, *LastNode = NULL;
};