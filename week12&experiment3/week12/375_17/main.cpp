//Modify function AllLengths so that it obtains a shortest path for all pairs of vertices. What is the computing time of your new function?
#include<iostream>
#include<Windows.h>
using namespace std;

#define nmax 6//顶点数
#define MAX 100//最大路径，表示不相连

class Graph
{
private:
	int length[nmax][nmax];//记录边的连通性和权重
	int a[nmax][nmax];//记录最短路径大小，不断比较更新
	
public:
	Graph()//初始化图
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


void Graph::addedge(int tail, int point, int value)//添加边与权重
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
	for(int k=0;k<nmax;k++)//k为新加入的点的坐标
		for (int i = 0; i < nmax; i++)
			for (int j = 0; j < nmax; j++)//对于新的k检查 所有边是否有两点间经过k且距离更近的路径，更新a数组
			{
				if ((a[i][k] + a[k][j]) < a[i][j])a[i][j] = a[i][k] + a[k][j];//判断i到j是否过k点且有无更短路径；
			}
	//输出每个顶点间最短距离
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