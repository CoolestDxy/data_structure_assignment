#pragma once
#include"TreeNode.h"
#include"Tree.h"
#include"LinkedStack.h"
class InorderIterator {
public:
	InorderIterator(Tree t) { CurrentNode = t.root; }
	char*Next()
	{
		while (CurrentNode)
		{
			s.Push(CurrentNode);
			CurrentNode = CurrentNode->leftChild;
		}
		if (!s.IsEmpty())
		{
			CurrentNode = s.Pop();
			char &temp = CurrentNode->data;
			CurrentNode = CurrentNode->rightChild;
			return &temp;
		}
		else return 0;
	}
	void Inorder()
	{
		char* a = Next();
		while (a)
		{
			cout << a;
			a = Next();
		}
	}
private:
	LinkedStack<TreeNode*>s;
	TreeNode*CurrentNode;
};


