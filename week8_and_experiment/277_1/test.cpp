//write a C++ function to insert a new node l as the left child of node s in a threaded binary tree.the left subtree becomes the left subtree of l;
#include"ThreadedTree.h"
using namespace std;

int main()
{
	ThreadedTree tree;
	cout << "the tree:\n     +\n   |   |\n   *   -\n  | |   |\n  / A   B" << endl;
	tree.Build();
	cout << "inorder threaded tree" << endl;
	tree.Inorder();
	cout << endl<<"insert a node '^' to the left of '*'" << endl;
	tree.testinsert();
	tree.Inorder();
	system("pause");
}