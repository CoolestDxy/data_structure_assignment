#pragma once
#include"Node.h"
template<class T>
class Node;
template<class T>
class List
{
public:
	List():av(0) { first = new Node<T>(); first->link = first; }
	~List() {
		if (first) {
			Node<T>*second = first->link;
			first->link = av;
			av = second;
			first = 0;
		}
	}
	bool IsEmpty() { return first == first->link; }
	void Add(Node<T> *x)
	{
			Node<T>*temp = first;
			while (temp->link != first)
				temp = temp->link;
			temp->link = x;
			x->link = first;
	}
	Node<T>* GetNode()
	{
		Node<T>*x;
		if (!av)x = new Node<T>;
		else { x = av; av = av->link; }
		return x;
	}
	void RetNode(Node<T>*x)
	{
		x->link = av;
		av = x;
	}

	Node<T>* first;
	Node<T>*av;
};
