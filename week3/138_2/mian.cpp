//����t�ι���ϱ�죬ͨ��ģ���ջ��ջʵ��������ϡ�
#include<iostream>
#include"Train.h"
using namespace std;

int main()
{
	int a[3] = { 1,2,3 }; int b[4] = { 1,2,3,4 };
	Train t(a, 3),t2(b,4); Train m;
	cout << "the 3 number train:" << endl;
	for(int i=0;i<3;i++)
		for (int j = 0; j < 2; j++)//���ں���ģ�����ջ�ı����鳤�ȣ���ʱû�ҵ��ݹ�ʵ�ֵİ취
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
			}//ͨ��������ֻ�ģ��Ľ��Ϊȫ��������ϣ�������©
	system("pause");
}