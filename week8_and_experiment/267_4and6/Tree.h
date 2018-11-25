#pragma once
#include<iostream>
#include"TreeNode.h"
#include"LinkedStack.h"
using namespace std;

class InorderIterator;
class Tree {
	friend class InorderIterator;
public:
	void Build()
	{
		TreeNode*a = new TreeNode('+');
		TreeNode*b = new TreeNode('*');
		TreeNode*c = new TreeNode('-');
		TreeNode*e = new TreeNode('/');
		TreeNode*f = new TreeNode('A');
		TreeNode*g = new TreeNode('B');
		a->leftChild = b;
		a->rightChild = c;
		b->leftChild = e;
		b->rightChild = f;
		c->rightChild = g;
		root = a;
	}
	void postorder()
	{
		TreeNode*CurrentNode = root,*LastNode=NULL;
		LinkedStack<TreeNode*>s;
		while (CurrentNode != 0)
		{
			s.Push(CurrentNode);
			CurrentNode = CurrentNode->leftChild;
		}
		while (!s.IsEmpty())
		{
			CurrentNode = s.gettop();
			s.Pop();

			if (CurrentNode->rightChild == 0 || CurrentNode->rightChild == LastNode)
			{	
				cout << CurrentNode->data;
				LastNode = CurrentNode;
			}
			
			else {
				s.Push(CurrentNode);
				CurrentNode = CurrentNode->rightChild;
				while (CurrentNode != 0)
				{
					s.Push(CurrentNode);
					CurrentNode = CurrentNode->leftChild;
				}
			}
		}
	}
	void preorder()
	{
		TreeNode*CurrentNode = root;
		LinkedStack<TreeNode*>s;
		while (!s.IsEmpty()||CurrentNode)
		{
			while (CurrentNode != 0)
				{
					s.Push(CurrentNode);
					cout << CurrentNode->data;
					CurrentNode = CurrentNode->leftChild;
				}
		
			if (!s.IsEmpty())
			{
				CurrentNode = s.gettop();
				s.Pop();
				CurrentNode = CurrentNode->rightChild;
				
			}
		
		}
	}
private:
	TreeNode*root;
};