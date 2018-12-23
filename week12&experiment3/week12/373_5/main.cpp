//Using the idea of ShortestPath,write a C++ function to find a minimum-cost spanning tree whose worst-case time is O(n2)
//Dijkstra算法
#include<iostream>
using namespace std;

#define nmax 6
#define MAX 100//最大路径，表示不相连

class Graph
{
private:
	int length[nmax][nmax];//记录边的连通性和权重
	int dist[nmax];//记录最短路径大小，不断比较更新
	bool s[nmax];//已找到最短路径的点集（路径长度会更新）
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
	void ShortestPath(const int, const int);
	int choose(const int);
	void addedge(int, int, int);
	void printShortPath();
};

int Graph::choose(const int x)//从剩下的点中找到路径最短的点
{
	int l = MAX; int r=0;
	for (int i = 0; i < nmax; i++)
	{
		if (s[i] == 0&&dist[i]<l)//未找到最短路径的点中有最短路径的点
		{
			l = dist[i];
			r = i;
		}
	}
	return r;//返回这个点的下标
}

void Graph::ShortestPath(const int n, const int v)//number and root，计算图的最短路径
{
	for (int i = 0; i < n; i++)//初始化dist数组
	{
		s[i] = 0;
		dist[i] = length[v][i];
	}
	s[v] = 1;
	dist[v] = 0;
	for (int i = 0; i < n - 2; i++)//依次取dist最小的点加入s集合，并判断是否会对原来距离产生影响
	{
		int u = choose(n);//获取最小的点
		s[u] = 1;
		for (int w = 0; w < n; w++)//比较是否产生新的最短路径
		{
			if (w == v)continue;
			if (!s[w])
				if (dist[u] + length[u][w] < dist[w])
					dist[w] = dist[u] + length[u][w];//如果产生新的最短路径，比较后更新
		}
	}
}

void Graph::addedge(int tail, int point, int value)//添加边与权重
{
	length[tail][point] = value;
}

void Graph::printShortPath()//打印最短路径
{
	for (int i = 0; i < nmax; i++)
	{
		cout << "0->" << i << ": " << dist[i] << endl;
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
	g.ShortestPath(nmax, 0);
	cout << "the shortest path: " << endl;
	g.printShortPath();
	system("pause");
}