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
	T Next()//后序遍历，需要判断当前节点的子节点是否都访问完成，需记录上一次访问的节点历史，
	{
		if (!s.IsEmpty()) {
			T temp;
			while (CurrentNode->rightChild != 0 && CurrentNode->rightChild != LastNode)//子节点有没访问的情况则循环遍历到子节点满足输出条件
			{
				CurrentNode = CurrentNode->rightChild;
				while (CurrentNode != 0)
				{
					s.Push(CurrentNode);
					CurrentNode = CurrentNode->leftChild;
				}
				CurrentNode = s.gettop();
			}
			CurrentNode = s.gettop();//获取需要输出的子节点
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