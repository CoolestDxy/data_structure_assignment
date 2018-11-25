#pragma once
template<class T>
class Stack
{
public:
	Stack(int stackCapacity=10);
	~Stack();
	bool IsEmpty()const;
	bool IsFull()const;
	T&Top()const;
	void Push(const T&item);
	void StackFull();
	void SplitStack();
	void Pop();
	void prints();
private:
	T *stack;
	int top;
	int capacity;
};

