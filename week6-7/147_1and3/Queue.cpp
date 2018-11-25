#include "Queue.h"
#include <iostream>
using namespace std;

template<class T>
Queue<T>::Queue(int queueCapacity):capacity(queueCapacity)
{
	if (capacity < 1)throw"Queu ecapacity must be >0";
	queue = new T[capacity];
	front = rear = 0;
	LastOp = 0;
}

template<class T>
inline bool Queue<T>::IsEmpty()const
{
	return rear == front && LastOp == 0;
}

template<class T>
inline bool Queue<T>::IsFull()const
{
	return rear == front && LastOp == 1;
}

template<class T>
inline T&Queue<T>::Front()const
{
	if (IsEmpty())throw"Queue is empty.No front element.";
	return queue[front % capacity];
}

template<class T>
inline T&Queue<T>::Rear()const
{
	if (IsEmpty())throw"Queue is empty,no rear element";
	return queue[rear];
}

template<class T>
void Queue<T>::Push(const T&x)
{
	if (IsFull()) {
		
	}
	queue[rear] = x;
	rear = (rear + 1) % capacity;
	LastOp = 1;
}

template<class T>
void Queue<T>::Pop()
{
	if (IsEmpty())throw"Queue is empty.Cannot delete.";
	front = (front + 1) % capacity;
	LastOp = 0;
}

template<class T>
void Queue<T>::print() {
	if(front<rear)
	for (int i = 0; i < rear; i++)
		cout <<" "<< queue[i]<<" " ;
	else if(front>=rear)
		for (int i = 0; i < rear+capacity; i++)
			cout << " " << queue[i%capacity] << " ";
	cout << endl;
}

template<class T>
void Queue<T>::split()
{
	Queue<T> temp1, temp2;
	if(front>=rear)
	for (int r = front; r <rear+capacity; r++)
	{
		if((r-front)%2==0)
		temp1.Push(queue[r]);
		else temp2.Push(queue[r]);
	}
	else for(int r = front; r < rear ; r ++)
	{
		if ((r - front) % 2 == 0)
			temp1.Push(queue[r]);
		else temp2.Push(queue[r]);
	}
	cout << "the first queue is :"<<endl;
	temp1.print();
	cout << "the second queue is:"<<endl;
	temp2.print();
}