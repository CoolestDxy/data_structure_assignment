//Write a set of C++ classes for manipulating graphs.Such a collection should allow input and output of arbitrary graphs,
//determining connected components,spanning trees,minimun-cost spanning trees,biconnected components,shortest paths,and so on.
#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<math.h>
using namespace std;

#define MAX 100//���·������ʾ������



int min2(int x,int y)
{
	if (x < y)return x;
	else return y;
}

struct Edge//�ñ߼�����¼ͼ������ͷβ��Ȩ��
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
	int** length;//��¼�ߵ���ͨ�Ժ�Ȩ��
	int* dist;//��¼���·����С�����ϱȽϸ���
	bool* s;//���ҵ����·���ĵ㼯��·�����Ȼ���£�
	int* parent;//
	Edge*edge;
	int *dfn;//����ͨ����
	int *low;
	stack<Edge>S;
	bool*visited;
public:
	Graph()//��ʼ��ͼ
	{
		int v, e;
		cout << "input the number of vertices and number of edges" << endl;
		cin >> v >> e;
		n = v;
		parent = new int[n];
		length = new int*[n];//˫��ָ���ʼ��
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


int Graph::CollapsingFind(int i)//�۵�Ѱ�ң�ֱ���ҵ����ڵ㣬���ӽڵ�ֱ�����������ڵ�
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

void Graph::WeightUnion(int r1, int r2)//��Ȩ�ϲ�
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
	cout << endl << "the minimum-cost spanning tree ��" << endl;
	sort(edge, edge + en,cmp);
	int sumweight = 0;
	int count = 0;
	int t, h;
	for (int i = 0; i < en; i++)//����С�����˳��ȡ����
	{
		t = edge[i].tail; h = edge[i].head;
		if (CollapsingFind(t) != CollapsingFind(h))//�жϱߵ�ͷβ�Ƿ�����ͬһ�����ڵ㣬�����γɻ�
		{
			cout << t << "-->" << h << ' ' << edge[i].weight << endl;//�������γɻ���ʱ�����һ����
			sumweight += edge[i].weight;//Ȩ���ۼ�
			count++;
			WeightUnion(t, h);//�������ڵ��������
		}
		if (count >= n - 1)break;//������Ϊ�ڵ�����һʱ���������
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

int Graph::choose(const int x)//��ʣ�µĵ����ҵ�·����̵ĵ�
{
	int l = MAX; int r = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 0 && dist[i] < l)//δ�ҵ����·���ĵ��������·���ĵ�
		{
			l = dist[i];
			r = i;
		}
	}
	return r;//�����������±�
}

void Graph::ShortestPath(const int n, const int v)//number and root������ͼ�����·��
{
	cout <<endl<< "the shortest path: " << endl;
	for (int i = 0; i < n; i++)//��ʼ��dist����
	{
		s[i] = 0;
		dist[i] = length[v][i];
	}
	s[v] = 1;
	dist[v] = 0;
	for (int i = 0; i < n - 2; i++)//����ȡdist��С�ĵ����s���ϣ����ж��Ƿ���ԭ���������Ӱ��
	{
		int u = choose(n);//��ȡ��С�ĵ�
		s[u] = 1;
		for (int w = 0; w < n; w++)//�Ƚ��Ƿ�����µ����·��
		{
			if (w == v)continue;
			if (!s[w])
				if (dist[u] + length[u][w] < dist[w])
					dist[w] = dist[u] + length[u][w];//��������µ����·�����ȽϺ����
		}
	}
}

void Graph::addedge(int tail, int point, int value)//��ӱ���Ȩ��
{
	length[tail][point] = value;
}

void Graph::printShortPath()//��ӡ���·��
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