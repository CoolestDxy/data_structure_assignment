#pragma once
#include<iostream>
using namespace std;
class WinnerTree//ʤ���������Ϊʤ�ߣ��ڵ㱣��ʤ��
{
public:
	WinnerTree(int h) { height = h; leaves = new int[h + 1]; successTree = new int[h]; }
	void adjust(int i)
	{
		int m, n;
		     if (2 * i < height)               /* ��ȡ�������ӽ�� */
			         m = successTree[2 * i];
		     else
			         m = 2 * i - height + 1;
		     if (2 * i + 1 < height)                 /* ��ȡ�����Һ��ӽڵ� */
			         n = successTree[2 * i + 1];
		     else
			         n = 2 * i -height + 2;
	   successTree[i] = leaves[m] > leaves[n] ? m : n; /* ����ʤ���ж� */

	}
	void init(int* a)
	{
		for (int i = 1; i <=height; i++)
		{
			leaves[i] = a[i-1];
		}
		for (int i = height - 1; i > 0; i--)
			adjust(i);
	}
	void changeagjust(int i)
	{
		int p = (i + height - 1) / 2;
		while (p > 0)
		{
			adjust(p);
			p = p / 2;
		}
	}
	int getwinner()
	{
		return successTree[1];
	}
private:
	int height;
	int *leaves;
	int *successTree;
};