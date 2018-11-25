#pragma once
#include<iostream>
using namespace std;
class LoserTree//败者树，小的为败者,败者树的中间节点储存比赛失败的节点，胜者继续进行下一轮比赛；
{
public:
	LoserTree(int h){ height = h; leaves = new int[h + 1]; losertree = new int[h+1]; }
	void adjust(int i)
	{
		int p = (i+height)/ 2;//找到叶子节点的父节点
		while (p > 0)//从叶子节点向上比较致根节点
		{
			if (leaves[i] <leaves[losertree[p]])//与败者树上的父节点比较，如果当前节点为败者，更新父节点败者，当前节点作为胜者传递上去
			{
				int temp = losertree[p];//交换
				losertree[p] = i;//父节点记录败者
				i = temp;//将胜者传递上去
			}
			p = p / 2;//继续寻找父节点败者，继续与胜者比较
		}
		losertree[0] = i;//储存胜者
}
	void init(int*a)
	{
		leaves[height] = 100;//设定最大值
		for (int i = 0; i < height; i++)
		{
			leaves[i] = a[i];
		}
		for (int i = 0; i <height; i++)
			losertree[i] = height;//初始化败者树为最大值
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