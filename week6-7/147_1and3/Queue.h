#pragma once
template<class T>
class Queue
{
public:
	Queue(int queueCapacity=10);
	bool IsEmpty()const;
	bool IsFull()const;
	T&Front()const;
	T&Rear()const;
	void Push(const T&item);
	void Pop();
	void print();
	void split();
private:
	T*queue;
	int front,
		rear,
		capacity;
	bool LastOp;
};

