//火车在t形轨道上变轨，通过模拟进栈出栈实现排列组合。
#include<iostream>
#include"Train.h"
using namespace std;

int main()
{
	int a[3] = { 1,2,3 }; int b[4] = { 1,2,3,4 };
	Train t(a, 3),t2(b,4); Train m;
	cout << "the 3 number train:" << endl;
	for(int i=0;i<3;i++)
		for (int j = 0; j < 2; j++)//由于函数模拟进出栈改变数组长度，暂时没找到递归实现的办法
		{
			m.set(t);
			m.run(i);
			m.run(j);
			m.run(0);
		}
	cout << "the 4 number train:" << endl;
	for(int i=0;i<4;i++)
		for(int j=0;j<3;j++)
			for (int k = 0; k < 2; k++)
			{
				m.set(t2);
				m.run(i);
				m.run(j);
				m.run(k);
				m.run(0);
			}//通过输出发现火车模拟的结果为全部排列组合，并无遗漏
	system("pause");
}