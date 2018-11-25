#include "Stack.h"


template<class T>
Stack<T>::Stack(int i)
{
	stack = new items[i];
	top = -1;
}

template<class T>
Stack<T>::~Stack()
{
}

template<class T>
void Stack<T>::Add(items x)
{
	stack[++top] = x;
}

template<class T>
items* Stack<T>::Delete(items& x)
{
	x = stack[top--];
	return& x;
}

template<class T>
void Stack<T>::Delete()
{
	top--;
}

template<class T>
bool Stack<T>::IsEmpty()
{
	return top == -1;
}