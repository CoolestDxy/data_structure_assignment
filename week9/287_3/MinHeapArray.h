#pragma once
#include<cmath>
#include<iostream>
using namespace std;

template<class T>
class MinHeap {
public:
	MinHeap(int theCapacity = 10) {
		if (theCapacity < 1)throw"capacity must be >=1";
		capacity = theCapacity;
		heapSize = -1;
		heap = new T[capacity + 1];
	}
	MinHeap(const MinHeap& x) {
		delete heap;
		heapSize = x.heapSize;
		capacity = x.capacity;
		heap = new T[capacity];
		for (int i = 0; i < heapSize; i++)
			heap[i] = x.heap[i];
	}
	~MinHeap() {
		delete heap;
	}
	bool IsEmpty()const
	{
		return heapSize == -1;
	}
	const T&Top()const {
		return heap[heapSize];
	}
	void Push(const T& e) {
		if (heapSize == capacity) {
			Doublesize();
		}
		int currentNode = ++heapSize;
		while (currentNode != 0 && heap[currentNode / 2] > e)//与父母节点判断确定插入位置
		{
			heap[currentNode] = heap[currentNode / 2];
			currentNode /= 2;
		}
		heap[currentNode] = e;
	}
	void pop()
	{
		T last = heap[heapSize--];//保存尾节点用于插入
		int Cur = 0;//当前节点（根节点）
		int child = 1;//当前节点的子节点
		while (child <= heapSize)
		{
			if (child < heapSize&&heap[child] >heap[child + 1])child++;//找到两个孩子最小的
			if (last <= heap[child])break;//找到插入位置
			heap[Cur] = heap[child];//替换根节点位置（last插入点）
			Cur = child;//待插入节点移动
			child *= 2;//移动到孩子节点
		}
		heap[Cur] = last;//插入尾节点，删除根节点
	}
	void newInsertion(T& e) {
		if (heapSize == capacity) {
			Doublesize();
		}
		int currentNode = ++heapSize;
		heap[currentNode] = e;
		sort(currentNode);
	}
	void sort(int index) {
		if (index > 0) {
			int parent = index / 2;
			if (heap[parent] > heap[index]) {
				T temp = heap[index];
				heap[index] = heap[parent];
				heap[parent] = temp;
				sort(parent);
			}
		}
	}
		void Doublesize()
	{
		T*temp = new T[capacity * 2 + 1];
		for (int i = 0; i < capacity; i++)
		{
			temp[i] = heap[i];
		}
		capacity *= 2;
		delete heap;
		heap = temp;
		temp = nullptr;
	}
	void print()
	{
		for (int i = 0; i <= heapSize; i++)
			cout << heap[i] << ' ';
	}

private:
	T*heap;
	int heapSize;
	int capacity;
};