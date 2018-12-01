//Kruskal's minimum-cost spanning tree algorithm as a complete program.
#include<iostream>
#include<algorithm>
using namespace std;

int *parent;
int v, e;

struct Edge//用边集来记录图，包括头尾和权重
{
	int tail;
	int head;
	int weight;
}*edge;

void init()//初始化图
{
	
	cout << "input the number of vertices and edges:" << endl;
	cin >> v >> e;
	parent = new int[v];
	for (int i = 0; i < v; i++)
		parent[i] = -1;
	edge = new Edge[e];
	cout << "input the tail,head,weight of the edges:" << endl;
	int n, m, w;
	for (int i = 0; i < e; i++)
	{
		cin >> n >> m >> w;
		edge[i].tail = n;
		edge[i].head = m;
		edge[i].weight = w;
	}

}

int CollapsingFind(int i)//折叠寻找，直接找到根节点，将子节点直接连结至根节点
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

void WeightUnion(int r1, int r2)//加权合并
{
	int i = CollapsingFind( r1);
	int j = CollapsingFind( r2);
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


bool cmp(Edge a, Edge b)
{
	return a.weight <= b.weight;
}

void Kruskal()
{
	int sumweight = 0;
	int count=0;
	int t, h;
	for (int i = 0; i < e; i++)//按从小到大的顺序取出边
	{
		t = edge[i].tail; h = edge[i].head;
		if (CollapsingFind(t) != CollapsingFind(h))//判断边的头尾是否属于同一个根节点，避免形成环
		{
			cout << t << "-->" << h << ' ' << edge[i].weight<<endl;//当不会形成环的时候，输出一条边
			sumweight += edge[i].weight;//权重累加
			count++;
			WeightUnion(t, h);//将两个节点进行连接
		}
		if (count >= v - 1)break;//当边数为节点数减一时，生成完毕
	}
	cout << "the sum weight: " << sumweight << endl;
}

int main()
{
	init();
	sort(edge, edge + e, cmp);
	Kruskal();
	system("pause");
}