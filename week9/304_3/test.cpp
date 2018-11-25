//prove that the preorder traversal of a forest and the preorder traversal of its associated binary tree give the same result
#include"Forest.h"
using namespace std;
int main()
{
	Tree t1, t2;
	t1.build1();
	t2.build2();
	Forest f;
	f.addtree(t1);
	f.addtree(t2);
	cout << "preorder for tree1: " << endl;
	t1.preorder();
	cout << endl << "preorder for tree2: " << endl;
	t2.preorder();
	cout <<endl<< "preorder for forest: " << endl;
	f.forestPreorder();
	system("pause");
}