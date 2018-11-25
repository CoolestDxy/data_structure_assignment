#pragma once
#include"LinkedList.h"
class LinkedList;
class Node
{
	friend class LinkedList;
public:
	Node(int x = 0) {
		data = x;
		link =0;
	}
private:
	int data;
	Node* link;
};

