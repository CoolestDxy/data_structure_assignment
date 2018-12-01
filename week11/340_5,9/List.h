#pragma once
template<class T>
class List
{
	friend class Graph;
public:
	List(T d = 0) { data = d; link = 0; }
private:
	T data;
	List<T>*link;
};