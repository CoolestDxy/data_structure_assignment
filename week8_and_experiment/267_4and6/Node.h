#pragma once
#pragma once
template<class T>
class LinkedStack;
template<class T>
class Node
{
	friend class LinkedStack<T>;
public:
	Node(T d = 0)
	{
		data = d;
		link = 0;
	}

private:
	T data;
	Node<T>*link;
};
