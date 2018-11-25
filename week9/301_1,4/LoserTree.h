#pragma once
#include<iostream>
using namespace std;
class LoserTree//��������С��Ϊ����,���������м�ڵ㴢�����ʧ�ܵĽڵ㣬ʤ�߼���������һ�ֱ�����
{
public:
	LoserTree(int h){ height = h; leaves = new int[h + 1]; losertree = new int[h+1]; }
	void adjust(int i)
	{
		int p = (i+height)/ 2;//�ҵ�Ҷ�ӽڵ�ĸ��ڵ�
		while (p > 0)//��Ҷ�ӽڵ����ϱȽ��¸��ڵ�
		{
			if (leaves[i] <leaves[losertree[p]])//��������ϵĸ��ڵ�Ƚϣ������ǰ�ڵ�Ϊ���ߣ����¸��ڵ���ߣ���ǰ�ڵ���Ϊʤ�ߴ�����ȥ
			{
				int temp = losertree[p];//����
				losertree[p] = i;//���ڵ��¼����
				i = temp;//��ʤ�ߴ�����ȥ
			}
			p = p / 2;//����Ѱ�Ҹ��ڵ���ߣ�������ʤ�߱Ƚ�
		}
		losertree[0] = i;//����ʤ��
}
	void init(int*a)
	{
		leaves[height] = 100;//�趨���ֵ
		for (int i = 0; i < height; i++)
		{
			leaves[i] = a[i];
		}
		for (int i = 0; i <height; i++)
			losertree[i] = height;//��ʼ��������Ϊ���ֵ
		for (int i = height-1; i >=0; i--)
		{
			adjust(i);
		}
	}
	int getloser(){
		return leaves[losertree[1]];
	}
	int getwinner() {
		return leaves[losertree[0]];
	}
private:
	int height;
	int* leaves;
	int*losertree;
};