#pragma once
#include<Windows.h>
#include<stdlib.h>
#include<ctime>
class Sets
{
public:
	Sets(int sz = 100) {
		n = sz;
		parent = new int[sz];
		for (int i = 0; i < n; i++)
			parent[i] = -1;
	}
	void buildfortest()
	{
		parent[0] = -1;
		parent[1] = parent[2] = 0;
		parent[3] = parent[4] = 1;
		parent[5] = -1;
		parent[6] = parent[7] = parent[8] = 5;
		parent[9] = -1;
		parent[10] = 9;
	}
	void SimpleUnion(int i, int j)
	{
		parent[i] = j;
	}
	int Simplefind(int i)
	{
		while (parent[i] >= 0)
			i = parent[i];
		return i;
	}
	void WeightUnion(int i, int j)
	{
		int temp = parent[i] + parent[j];
		if (parent[i] > parent[j])
		{
			parent[i] = j;
			parent[j] = temp;
		}
		else {
			parent[j] = i;
			parent[i] = temp;
		}
	}
	int CollapsingFind(int i)
	{
		int r;
		for ( r= i; parent[r] >= 0; r = parent[r]);
		while (i != r) {
			int s = parent[i];
			parent[i] = r;
			i = s;
		}
		return r;
	}
private:
	int *parent;
	int n;
};