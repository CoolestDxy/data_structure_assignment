//272_1:write a C++function to count the number of leaf nodes in a binary tree.Computin time?
//273_4:write a recursive function to delete all nodes in a binary tree.complexity?
#include<Windows.h>
#include"Tree.h"
using namespace std;

int main()
{
	Tree a;
	a.Build();
	float t1 = GetTickCount();
	for (int i = 0; i < 10000;i++)
		a.countleaves();
	float t2 = GetTickCount();
	cout << "cause time:" << (t2 - t1 )/10000000<< "second" << endl;
	cout << "the number of the leaves of the tree is:" << endl;
	cout << a.countleaves() << endl;
	a.deletetree();
	cout << "the complexity of the delete function is O(n*lgn)" << endl;
	system("pause");
}