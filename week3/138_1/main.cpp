#include<iostream>
#include"Stack.h"
#include"Stack.cpp"
using namespace std;

int main()
{
	Stack<int> stk(20);
	for (int i = 0; i < 20; i++)
		stk.Push(i);
	stk.SplitStack();
	system("pause");
}