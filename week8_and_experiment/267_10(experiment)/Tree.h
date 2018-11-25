#pragma once
#include<iostream>
#include"TreeNode.h"
#include"LinkedStack.h"
using namespace std;

template<class T>
class InorderIterator;
template<class T>
class PostorderIterator;
template<class T>
class PreorderIterator;
template<class T>
class LevelorderIterator;
template<class T>
class Tree {
	friend class InorderIterator<T>;
	friend class PostorderIterator<T>;
	friend class PreorderIterator<T>;
	friend class LevelorderIterator<T>;
	friend void Bluidtree(Tree<char>&x)
	{
		TreeNode<char>*a = new TreeNode<char>('+');
		TreeNode<char>*b = new TreeNode<char>('*');
		TreeNode<char>*c = new TreeNode<char>('-');
		TreeNode<char>*e = new TreeNode<char>('/');
		TreeNode<char>*f = new TreeNode<char>('A');
		TreeNode<char>*g = new TreeNode<char>('B');
		a->leftChild = b;
		a->rightChild = c;
		b->leftChild = e;
		b->rightChild = f;
		c->rightChild = g;
		x.root = a;
	}
public:
	Tree(Tree<T>&x) {
		root = x.root;
	}
	Tree(TreeNode<T>*x=0) { root = x; }
	bool IsEmpty() {
		return root == 0;
	}
	Tree(Tree<T>&bt1, T&item, Tree&bt2)
	{
		TreeNode<T>*itemroot(item);
		itemroot->leftChild = bt1.root;
		itemroot->rightChild = bt2.root;
		Tree<T> temp(itemroot);
		return temp;
	}
	Tree<T>LeftSubtree()
	{
		Tree<T> temp(root->leftChild);
		return temp;
	}
	Tree<T>RightSubtree()
	{
		Tree<T> temp(root->rightChild);
		return temp;
	}
	T Rootdata()
	{
		return root->data;
	}
private:
	TreeNode<T>*root;
};


