//Write a set of C++ classes for manipulating graphs.Such a collection should allow input and output of arbitrary graphs,
//determining connected components,spanning trees,minimun-cost spanning trees,biconnected components,shortest paths,and so on.
#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<math.h>
using namespace std;

#define MAX 100//最大路径，表示不相连



int min2(int x,int y)
{
	if (x < y)return x;
	else return y;
}

struct Edge//用边集来记录图，包括头尾和权重
{
	int tail;
	int head;
	int weight;
};

bool cmp(Edge a, Edge b)
{
	return a.weight <= b.weight;
}

class Graph
{
private:
	int connected;//connect
	int n;//vertices
	int en;//edges
	int** length;//记录边的连通性和权重
	int* dist;//记录最短路径大小，不断比较更新
	bool* s;//已找到最短路径的点集（路径长度会更新）
	int* parent;//
	Edge*edge;
	int *dfn;//重连通分量
	int *low;
	stack<Edge>S;
	bool*visited;
public:
	Graph()//初始化图
	{
		int v, e;
		cout << "input the number of vertices and number of edges" << endl;
		cin >> v >> e;
		n = v;
		parent = new int[n];
		length = new int*[n];//双重指针初始化
		for (int i = 0; i < n; i++)
		{
			length[i] = new int[n];
			parent[i] = -1;
		}
		dist = new int[n];
		s = new bool[n];
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				length[i][j] = MAX;
				if (i == j)length[i][j] = 0;
			}
		edge = new Edge[e];
		en = e;
		int x, m, w;
		cout << "input the tail,point,weight" << endl;
		for (int i = 0; i < e; i++)
		{
			cin >> x >> m >> w;
			addedge(x, m, w);
			edge[i].tail = x;
			edge[i].head = m;
			edge[i].weight = w;
		}
		visited = new bool[n];
		for (int i = 0; i < n; i++)visited[i] = 0;
		connected = 0;
	}
	void ShortestPath(const int, const int);
	int choose(const int);
	void addedge(int, int, int);
	void printShortPath();
	void BFS(int);
	void Biconnected();
	void Biconnected(const int,const int,int );
	int CollapsingFind(int);
	void WeightUnion(int, int);
	void Kruskal();
};


int Graph::CollapsingFind(int i)//折叠寻找，直接找到根节点，将子节点直接连结至根节点
{
	int r;
	for (r = i; parent[r] >= 0; r = parent[r]);
	while (i != r) {
		int s = parent[i];
		parent[i] = r;
		i = s;
	}
	return r;
}

void Graph::WeightUnion(int r1, int r2)//加权合并
{
	int i = CollapsingFind(r1);
	int j = CollapsingFind(r2);
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



void Graph::Kruskal()
{
	cout << endl << "the minimum-cost spanning tree ：" << endl;
	sort(edge, edge + en,cmp);
	int sumweight = 0;
	int count = 0;
	int t, h;
	for (int i = 0; i < en; i++)//按从小到大的顺序取出边
	{
		t = edge[i].tail; h = edge[i].head;
		if (CollapsingFind(t) != CollapsingFind(h))//判断边的头尾是否属于同一个根节点，避免形成环
		{
			cout << t << "-->" << h << ' ' << edge[i].weight << endl;//当不会形成环的时候，输出一条边
			sumweight += edge[i].weight;//权重累加
			count++;
			WeightUnion(t, h);//将两个节点进行连接
		}
		if (count >= n - 1)break;//当边数为节点数减一时，生成完毕
	}
	cout << "the sum weight: " << sumweight << endl;
}


void Graph::Biconnected()
{
	int num = 1;
	dfn = new int[n];
	low = new int[n];
	for (int i = 0; i < n; i++)dfn[i] = low[i] = 0;
	Biconnected(0, -1,num);
	delete[]dfn;
	delete[]low;
}

void Graph::Biconnected(const int u, const int v, int num)
{
	dfn[u] = low[u] = num++;
	for (int w = 0; length[u][w] != MAX && length[u][w] != 0; w++)
	{
		if ((v != w) && (dfn[w] < dfn[u])) {
			for (int i = 0; i < en; i++)
			{
				if (edge[i].tail == u && edge[i].head == w)S.push(edge[i]);
			}
		}
		if (dfn[w] == 0) {
			Biconnected(w, u, num);
			low[u] = min2(low[u], low[w]);

			if (low[w] >= dfn[u]) {
				cout << "new biconnected component:" << endl;
				Edge o;
				do {
					o = S.top();
					S.pop();
					cout << o.tail << "," << o.head << endl;
				} while (o.tail != u && o.head != w);
			}
		}
		else if (w != v)low[u] = min2(low[u], dfn[w]);
	}

}

void Graph::BFS(int root)
{
	connected++;
	cout <<endl<< "BFS:" << endl;
	queue<int>q;
	q.push(root);

	while (!q.empty())
	{
		root = q.front();
		q.pop();
	cout << root << ",";
	for (int i = 0; i < n; i++)
	{
		if (length[root][i] != MAX && length[root][i] != 0 && visited[i] == 0)
		{
			q.push(i);
			visited[i] = 1;
		}
	}
	}
	cout << endl;
	//bool f=0;
	//for (int i = 0; i < n; i++)
	//	if (visited[i] == 0){f = 1; root=i;}
	//if(f==1){BFS(root); }
	//else cout << "the connected component is: " << connected << endl;
}

int Graph::choose(const int x)//从剩下的点中找到路径最短的点
{
	int l = MAX; int r = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 0 && dist[i] < l)//未找到最短路径的点中有最短路径的点
		{
			l = dist[i];
			r = i;
		}
	}
	return r;//返回这个点的下标
}

void Graph::ShortestPath(const int n, const int v)//number and root，计算图的最短路径
{
	cout <<endl<< "the shortest path: " << endl;
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
	ShortestPath(n, 0);
	for (int i = 0; i < n; i++)
	{
		cout << "0->" << i << ": " << dist[i] << endl;
	}
}
int main()
{
	Graph g;
	g.BFS(0);
	g.Kruskal();
	g.printShortPath();
	g.Biconnected();
	system("pause");
}