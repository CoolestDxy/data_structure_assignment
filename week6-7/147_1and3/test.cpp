//1.write queue using LastOp to judge whether the queue is empty or full
//2.write split() function to split the queue into two queues.The first queue is to contain every other element beginning with the first,second queue contains the remaining;
#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
using namespace std;

int main()
{
	Queue<int> a;
	for (int i = 0; i < 10; i++)
		a.Push(i);
	cout << "the queue is: "<<endl;
	a.print();
	a.split();//the complexity of my function is O(n)
	system("pause");
}