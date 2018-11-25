#include "Stack.h"
#include<iostream>
using namespace std;

template<class T>
void Stack<T>::prints()
{
	for (int i = top;i>=0; i--)
		cout << ' '<< stack[i]<<' ';
	cout << endl;
}

template<class T>
Stack<T>::Stack(int stackCapacity):capacity(stackCapacity)
{
	if (capacity < 1)throw"Stack capacity must be>0";
	stack = new T[capacity];
	top = -1;
}

template<class T>
Stack<T>::~Stack()
{
}

template<class T>
void Stack<T>::SplitStack()
{
	Stack a(capacity), b(capacity);
	for (int i = 0; i < capacity / 2; i++)
	{
		a.Push(stack[i]);
		b.Push( stack[i + capacity / 2]);
	}
	cout << "the original stack is: " << endl;
	prints();
	cout << "split into two stacks: " << endl;
	a.prints();
	b.prints();
	for (int i = 0; i < capacity / 2; i++)
	{
		a.Push(b.stack[i]);
	}
	cout << "combine two stack: " << endl;
	a.prints();
}
template<class T>
bool Stack<T>::IsEmpty()const { return top == -1; }

template<class T>
bool Stack<T>::IsFull()const { return top == capacity - 1; }

template<class T>
T&Stack<T>::Top()const
{
	if (IsEmpty())throw"Stack is empty";
	return stack[top];
}

template<class T>
void Stack<T>::Push(const T&x)
{
	if (IsFull())StackFull();
	else stack[++top] = x;
}

template<class T>
void Stack<T>::StackFull()
{
	T *temp = new T[capacity*2];
	for (int i = 0; i < capacity; i++)
	{
		temp[i] = stack[i];
	}
	capacity *= 2;
	delete[] stack;
	stack = temp;
}

template<class T>
void Stack<T>::Pop()
{
	if (IsEmpty()) {  return ; }
	stack[top--].~T();
}