//No.1:develop and test a complete C++ template class for linked stackes
//No.2:develop and test a complete C++ template class for linked queues
#pragma once
#include<iostream>
#include"LinkedQueue.h"
#include"LinkedStack.h"
using  namespace std;

int main()
{
	//No.1:
	cout << "test for linkedstack: " << endl;
	LinkedStack<int> k;
	for (int i = 0; i < 5; i++)
	{
		k.Push(i);
	}
	cout << "the stack: " << endl;
	k.print();
	cout << "after popping from stack" << endl;
	k.Pop();
	k.print();
	//No.2:
	LinkedQueue<int>q;
	for (int i = 0; i < 5; i++)
	{
		q.Push(i);
	}
	cout << endl << "test for linkedqueue" << endl<<"the queue: "<<endl;
	q.print();
	q.Pop();
	cout << "after queue popping: " << endl;
	q.print();
	system("pause");
	return 0;
}