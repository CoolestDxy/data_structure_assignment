#pragma once
template<class T>
struct Dictionary
{
	Dictionary(int k=0, T x=0) :key(k), d(x) {}
	int key;
	T d;
};
template<class T>
class Bst;
template<class T>
class BstNode
{
	friend class Bst<T>;
public:
	BstNode() { data = new Dictionary<T>(); lChild = rChild = 0; }
private:
	Dictionary<T>*data;
	int leftsize;
	BstNode<T>*lChild;
	BstNode<T>*rChild;
};