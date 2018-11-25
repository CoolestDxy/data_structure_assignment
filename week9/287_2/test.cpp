//write a C++ abstruct class similar to ADT 5.2 for the ADT MinPQ,which defines a min priority queue.
//Now write a C++class MinHeap theat derives from this abstract class and implement all the virtual functions of MinPQ;	
#include<iostream>
#include"MinHeap.h"
using namespace std;

int main()
{
	MinHeap<int>minheap;
	for (int i = 10; i > 0; i--)
		minheap.Push(i);
	cout << "the max heap:" << endl;
	minheap.print();
	cout << endl<<"poping the root node:"<<endl;
	minheap.pop();
	minheap.print();
	system("pause");
}