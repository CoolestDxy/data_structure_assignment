//Modify function AllLengths so that it obtains a shortest path for all pairs of vertices. What is the computing time of your new function?
#include<iostream>
#include<Windows.h>
using namespace std;

#define nmax 6//������
#define MAX 100//���·������ʾ������

class Graph
{
private:
	int length[nmax][nmax];//��¼�ߵ���ͨ�Ժ�Ȩ��
	int a[nmax][nmax];//��¼���·����С�����ϱȽϸ���
	
public:
	Graph()//��ʼ��ͼ
	{
		for (int i = 0; i < nmax; i++)
			for (int j = 0; j < nmax; j++)
			{
				length[i][j] = MAX;
				if (i == j)length[i][j] = 0;
			}
	}
	void addedge(int, int, int);
	void AllLength();
};


void Graph::addedge(int tail, int point, int value)//��ӱ���Ȩ��
{
	length[tail][point] = value;
}

void Graph::AllLength()
{
	for(int i=0;i<nmax;i++)
		for (int j = 0; j < nmax; j++)
		{
			a[i][j] = length[i][j];//initialize the a
		}
	for(int k=0;k<nmax;k++)//kΪ�¼���ĵ������
		for (int i = 0; i < nmax; i++)
			for (int j = 0; j < nmax; j++)//�����µ�k��� ���б��Ƿ�������侭��k�Ҿ��������·��������a����
			{
				if ((a[i][k] + a[k][j]) < a[i][j])a[i][j] = a[i][k] + a[k][j];//�ж�i��j�Ƿ��k�������޸���·����
			}
	//���ÿ���������̾���
	cout << "the shortestpath of every two vertices:" << endl;
	for(int i=0;i<nmax;i++)
		for (int j = 0; j < nmax; j++)
		{
			cout << i << "->" << j << ":   " << a[i][j] << endl;
		}
}

int main()
{
	Graph g;
	g.addedge(1, 4, 10);
	g.addedge(1, 0, 2);
	g.addedge(1, 5, 30);
	g.addedge(2, 3, 4);
	g.addedge(2, 5, 10);
	g.addedge(4, 3, 15);
	g.addedge(5, 4, 10);
	g.addedge(5, 3, 4);
	g.addedge(0, 1, 20);
	g.addedge(0, 2, 15);
	float t1 = GetTickCount();
	g.AllLength();
	float t2 = GetTickCount();
	cout << "the running time is:  "<<t2-t1 <<"ms"<< endl;
	system("pause");
}