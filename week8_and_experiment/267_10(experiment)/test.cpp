//experiment 267_10:develop a complete C++ template class for binary trees,You must include a constructor,
//copy constructor,destructor,the four traversal methods of this section together with forword iterators for each.
//Include also he remaining functions specified in ADT5.1
#include<iostream>
#include"Tree.h"
#include"TreeNode.h"
#include"InorderIterator.h"
#include"PostorderIterator.h"
#include"PreorderIterator.h"
#include"LevelorderIterator.h"
using namespace std;

int main()
{
	Tree<char>a;
	Bluidtree(a);
	cout << "the tree:\n     +\n   |   |\n   *   -\n  | |   |\n  / A   B" << endl;//打印树的内容，Bulid为Tree的友元函数，用来建立测试用例
	cout << "test for inorder iterator:" << endl;
	InorderIterator<char> inIt(a);
	inIt.Inorder();
	cout << endl << "test for postorder iterator" << endl;
	PostorderIterator<char>poIt(a);
	poIt.postorder();
	cout << endl << "test for preorderiteraror" << endl;
	PreorderIterator<char>preIt(a);
	preIt.preorder();
	cout << endl << "test for levelorderiteraror" << endl;
	LevelorderIterator<char>levIt(a);
	levIt.levelorder();
	cout << endl<<"the sublefttree for inorder traversal:" << endl;
	a = a.LeftSubtree();
	InorderIterator<char> subinIt(a);
	subinIt.Inorder();
	cout << endl;
	system("pause");
}