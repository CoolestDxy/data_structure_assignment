//write an insertion algorithm that use  the strategy (binary search) to insert and re do exsercsie 1
#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include"MinHeapArray.h"
using namespace std;

int main()
{
	
	MinHeap<int>minheap;
	for (int i = 0; i < 4000; i++)
	{
		int t = rand();
		minheap.newInsertion(t);
	}
	float t1 = GetTickCount();
	for (int i = 0; i < 100000; i++)
	{
		int t = rand();
		if (t % 2)minheap.newInsertion(t);
		else {
			if(minheap.IsEmpty())minheap.newInsertion(t);
			else minheap.pop();
		}
	}
	float t2= GetTickCount();
	cout << "for m=1000,n=4000,cost time: " << (t2 - t1)/100000<<"ms"<<endl;
	system("pause");
}