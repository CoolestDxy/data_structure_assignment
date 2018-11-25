//write a function to traverse a threaded binary tree in pre order .What are time and space aquirements?
#include"ThreadedTree.h"
using namespace std;


int main()
{
	ThreadedTree tree;
	cout << "the tree:\n     +\n   |   |\n   *   -\n  | |   |\n  / A   B" << endl;
	tree.Build();
	cout << "preorder threaded tree" << endl;
	tree.preorder();
	system("pause");
}