#pragma once
class ThreadedNode
{
	friend class ThreadedTree;
public:
	ThreadedNode(char x = 0) { data = x; LeftThread = RightThread = 1; leftChild = rightChild = 0; }
	void addleft(ThreadedNode*x) { leftChild = x; LeftThread = 0; }
	void addright(ThreadedNode*x) { rightChild = x; RightThread = 0; }
private:
	bool LeftThread, RightThread;
	ThreadedNode*leftChild, *rightChild;
	char data;
};