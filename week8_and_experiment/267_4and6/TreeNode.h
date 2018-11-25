#pragma once
class Tree;
class InorderIterator;

class TreeNode
{
	friend class Tree;
	friend class InorderIterator;
public:
	TreeNode() { leftChild = rightChild = 0; }
	TreeNode(char x) { data = x;  leftChild = rightChild = 0;
	}
private:
	char data;
	TreeNode*leftChild;
	TreeNode*rightChild;
};