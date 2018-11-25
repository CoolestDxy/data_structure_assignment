#pragma once
#include"LinkedQueue.h"
#include"LinkedStack.h"
template<class T>
class LinkedQueue;
template<class T>
class LinkedStack;
template<class T>
class Node
{
	friend class LinkedQueue<T>;
	friend class LinkedStack<T>;
public:
	Node(T d= 0)
	{
		data = d;
		link = 0;
	}
	Node(T x, Node<T>*y)
	{
		data = x;
		link = y;
	}
private:
	T data;
	Node<T>*link;
};
