#pragma once
#include"List.h"

template<class T>
class List;
template<class T>
class Node
{
	friend class List<T>;
public:
	Node(T x) :data(x), link(0) {}
	Node() :link(0) { }
	T data;
	Node<T>*link;
};
