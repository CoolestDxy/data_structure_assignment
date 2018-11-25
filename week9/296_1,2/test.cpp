//No.1：write a C++ function to delete the pair with key k from a binary search tree.complexity?
//No.2:write a program to start with an initially empty binary search tree and make nrandom insertions.
//Use a uniform random number generator to obtain the values to be inserted.Measure the height of the resulting binary search treee
//and divide this height by log2n.n=100,500,1000,2000,3000,...10000.Plot the ratio height/log2n as afunction of n
#include<iostream>
#include<Windows.h>
#include <stdlib.h>
#include <time.h> 
#include<cmath>
#include"Bst.h"
using namespace std;

int main()
{
	cout << "teat for question1:" << endl;//题1
	Bst<int>tree;
	int a[7] = { 6,3,8,1,4,7,10 };
	for (int i = 0; i < 7; i++)
	{
		tree.Insert(Dictionary<int>(a[i], 0));
	}
	cout << "inorder print the search tree:" << endl;
	tree.inorderprint();
	cout << endl<<"delete key8" << endl;
	tree.Delete(8);
	tree.inorderprint();
	cout << endl << "height: " << tree.findheight()<<endl;

	cout << endl<<"test for question2:\nprint the ratio from n=100,500,1000...to n=10000: " << endl;
	srand((unsigned)time(NULL));//题2：计算从n=100到10000的height/lg2n结果打印在屏幕上：
	float lg,ratio;
	int height,n;
	//n=100
	n = 100;
	Bst<int>tree1;
	for (int i = 0; i < n; i++)
	{
		tree1.Insert(rand() % n);
	}
	height = tree1.findheight();
	lg = log(n) / log(2);
	ratio =  height/lg ;
	cout << ratio<<endl;
	//n=500
	srand((unsigned)time(NULL));
	n = 500;
	Bst<int>tree2;
	for (int i = 0; i < n; i++)
	{
		tree1.Insert(rand() % n);
	}
	height = tree1.findheight();
	lg = log(n) / log(2);
	ratio = height/lg;
	cout << ratio<<endl;
	//n=1000
	srand((unsigned)time(NULL));
	n = 1000;
	Bst<int>tree3;
	for (int i = 0; i < n; i++)
	{
		tree1.Insert(rand() % n);
	}
	height = tree1.findheight();
	lg = log(n) / log(2);
	ratio = height/lg;
	cout << ratio << endl;
	//n=2000
	srand((unsigned)time(NULL));
	n = 2000;
	Bst<int>tree4;
	for (int i = 0; i < n; i++)
	{
		tree1.Insert(rand() % n);
	}
	height = tree1.findheight();
	lg = log(n) / log(2);
	ratio = height/lg  ;
	cout << ratio << endl;
	//n=3000
	srand((unsigned)time(NULL));
	n = 3000;
	Bst<int>tree5;
	for (int i = 0; i < n; i++)
	{
		tree1.Insert(rand() % n);
	}
	height = tree1.findheight();
	lg = log(n) / log(2);
	ratio = height / lg;
	cout << ratio << endl;
	//n=4000
	srand((unsigned)time(NULL));
	n = 4000;
	Bst<int>tree6;
	for (int i = 0; i < n; i++)
	{
		tree1.Insert(rand() % n);
	}
	height = tree1.findheight();
	lg = log(n) / log(2);
	ratio = height / lg;
	cout << ratio << endl;
	//n=5000
	srand((unsigned)time(NULL));
	n = 5000;
	Bst<int>tree7;
	for (int i = 0; i < n; i++)
	{
		tree1.Insert(rand() % n);
	}
	height = tree1.findheight();
	lg = log(n) / log(2);
	ratio = height / lg;
	cout << ratio << endl;
	//n=6000
	srand((unsigned)time(NULL));
	n = 6000;
	Bst<int>tree8;
	for (int i = 0; i < n; i++)
	{
		tree1.Insert(rand() % n);
	}
	height = tree1.findheight();
	lg = log(n) / log(2);
	ratio = height / lg;
	cout << ratio << endl;
	//n=7000
	srand((unsigned)time(NULL));
	n = 7000;
	Bst<int>tree9;
	for (int i = 0; i < n; i++)
	{
		tree1.Insert(rand() % n);
	}
	height = tree1.findheight();
	lg = log(n) / log(2);
	ratio = height / lg;
	cout << ratio << endl;
	//n=8000
	srand((unsigned)time(NULL));
	n = 8000;
	Bst<int>tree10;
	for (int i = 0; i < n; i++)
	{
		tree1.Insert(rand() % n);
	}
	height = tree1.findheight();
	lg = log(n) / log(2);
	ratio = height / lg;
	cout << ratio << endl;
	//n=9000
	srand((unsigned)time(NULL));
	n = 9000;
	Bst<int>tree11;
	for (int i = 0; i < n; i++)
	{
		tree1.Insert(rand() % n);
	}
	height = tree1.findheight();
	lg = log(n) / log(2);
	ratio = height / lg;
	cout << ratio << endl;
	//n=10000
	srand((unsigned)time(NULL));
	n = 10000;
	Bst<int>tree12;
	for (int i = 0; i < n; i++)
	{
		tree1.Insert(rand() % n);
	}
	height = tree1.findheight();
	lg = log(n) / log(2);
	ratio = height / lg;
	cout << ratio << endl;
	system("pause");
}