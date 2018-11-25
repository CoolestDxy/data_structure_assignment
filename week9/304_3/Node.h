#pragma once
class Tree;
class Node {
	friend class Tree;
public:
	Node(int d = 0) { data = d; lChild = rChild = 0; }
private:
	int data;
	Node*lChild;
	Node*rChild;
};