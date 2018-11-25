#pragma once

template<class T>
class MinPQ {
public:
	virtual ~MinPQ() {}
	virtual bool IsEmpty()const = 0;
	virtual const T&Top()const = 0;
	virtual void Push(const T&) = 0;
	virtual void pop() = 0;
};