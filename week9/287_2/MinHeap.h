#pragma once
#include<cmath>
#include<iostream>
#include"MinPQ.h"
using namespace std;
template<class T>
class MinPQ;
template<class T>
class MinHeap :public MinPQ<T> {
public:
	MinHeap(int theCapacity=10) {
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
	virtual bool IsEmpty()const
	{
		return heapSize == -1;
	}
	virtual const T&Top()const {
		return heap[heapSize];
	}
	virtual void Push(const T& e) {
		if (heapSize == capacity) {
			Doublesize();
		}
		int currentNode = ++heapSize;
		while (currentNode != 0&& heap[currentNode / 2] > e)//�븸ĸ�ڵ��ж�ȷ������λ��
		{
			heap[currentNode] = heap[currentNode / 2];
			currentNode /= 2;
		}
		heap[currentNode] = e;
	}
	virtual void pop()
	{
		T last = heap[heapSize--];//����β�ڵ����ڲ���
		int Cur = 0;//��ǰ�ڵ㣨���ڵ㣩
		int child = 1;//��ǰ�ڵ���ӽڵ�
		while (child <= heapSize)
		{
			if (child < heapSize&&heap[child] >heap[child + 1])child++;//�ҵ�����������С��
			if (last <= heap[child])break;//�ҵ�����λ��
			heap[Cur] = heap[child];//�滻���ڵ�λ�ã�last����㣩
			Cur = child;//������ڵ��ƶ�
			child *= 2;//�ƶ������ӽڵ�
		}
		heap[Cur] = last;//����β�ڵ㣬ɾ�����ڵ�
	}
	void Doublesize()
	{
		T*temp = new T[capacity*2 + 1];
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