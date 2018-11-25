//No.4:implement a forward iterator forTree,whilch traverse the tree in inorder;
//No.6:write a nonrecursion verion of function Preorder:
#include<iostream>
#include"InorderIterator.h"
#include"Tree.h"
using namespace std;

int main()
{
	Tree tree;
	tree.Build();//Bulid a binary tree
	InorderIterator it(tree);
	cout << "inorde iterator:" << endl;
	it.Inorder();//use iterator to visit through the tree
	cout << "\npreorder withnot recursion:" << endl;
	tree.preorder();
	system("pause");
}