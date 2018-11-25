#pragma once
#include<cstdio>
#include<queue>
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
class LevelorderIterator
{
public:
	LevelorderIterator(Tree<T> t) {
		s.push(t.root);
	}
	T Next()//层序遍历采用队列先进先出，
	{
		while (!s.empty()) {
			TreeNode<T>* temp;
			temp = s.front();
			s.pop();
			if (temp->leftChild != 0)
				s.push(temp->leftChild);
			if (temp->rightChild != 0)
				s.push(temp->rightChild);

			return temp->data;
		}
		return 0;
	}
	void levelorder()
	{
		T a = Next();
		while (a)
		{
			cout << a;
			a = Next();
		}
	}
private:
	queue<TreeNode<T>*>s;
};