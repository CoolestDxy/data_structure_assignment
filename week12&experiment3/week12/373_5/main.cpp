//Using the idea of ShortestPath,write a C++ function to find a minimum-cost spanning tree whose worst-case time is O(n2)
//Dijkstra�㷨
#include<iostream>
using namespace std;

#define nmax 6
#define MAX 100//���·������ʾ������

class Graph
{
private:
	int length[nmax][nmax];//��¼�ߵ���ͨ�Ժ�Ȩ��
	int dist[nmax];//��¼���·����С�����ϱȽϸ���
	bool s[nmax];//���ҵ����·���ĵ㼯��·�����Ȼ���£�
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
	void ShortestPath(const int, const int);
	int choose(const int);
	void addedge(int, int, int);
	void printShortPath();
};

int Graph::choose(const int x)//��ʣ�µĵ����ҵ�·����̵ĵ�
{
	int l = MAX; int r=0;
	for (int i = 0; i < nmax; i++)
	{
		if (s[i] == 0&&dist[i]<l)//δ�ҵ����·���ĵ��������·���ĵ�
		{
			l = dist[i];
			r = i;
		}
	}
	return r;//�����������±�
}

void Graph::ShortestPath(const int n, const int v)//number and root������ͼ�����·��
{
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