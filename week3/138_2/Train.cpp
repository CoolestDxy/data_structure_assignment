#include "Train.h"
#include<iostream>
using namespace std;


Train::Train(int* t,int l):length(l),flag(l)
{
	train = new int[l];
	for (int i = 0; i < l; i++)
	{
		train[i] = t[i];
	}
	top = length-1;
}

void Train::set(Train t)
{
	length = t.length;
	for (int i = 0; i < t.length; i++)
	{
		train[i] = t.train[i];
	}
	top = t.top;
}

Train::~Train()
{
}

void Train::run(int p)//模拟火车进站取第p号车厢出站，p号车厢之前的存在左侧车道，最后合并，为调用一次函数。
{
	if (top == 0) { cout << train[0] << endl; }
	else {
		Train temp;
		for (int i = top; i > top - p; i--)
		{

			temp.add(train[i]);
		}
		for (int k = 0; k < p; k++)
			del();
		cout << train[top];
		del();
		for (int m = temp.top; m > -1; m--)
		{
			add(temp.train[m]);
		}
		temp.~Train();
	}
}
