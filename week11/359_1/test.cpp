//Kruskal's minimum-cost spanning tree algorithm as a complete program.
#include<iostream>
#include<algorithm>
using namespace std;

int *parent;
int v, e;

struct Edge//�ñ߼�����¼ͼ������ͷβ��Ȩ��
{
	int tail;
	int head;
	int weight;
}*edge;

void init()//��ʼ��ͼ
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

int CollapsingFind(int i)//�۵�Ѱ�ң�ֱ���ҵ����ڵ㣬���ӽڵ�ֱ�����������ڵ�
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

void WeightUnion(int r1, int r2)//��Ȩ�ϲ�
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
	for (int i = 0; i < e; i++)//����С�����˳��ȡ����
	{
		t = edge[i].tail; h = edge[i].head;
		if (CollapsingFind(t) != CollapsingFind(h))//�жϱߵ�ͷβ�Ƿ�����ͬһ�����ڵ㣬�����γɻ�
		{
			cout << t << "-->" << h << ' ' << edge[i].weight<<endl;//�������γɻ���ʱ�����һ����
			sumweight += edge[i].weight;//Ȩ���ۼ�
			count++;
			WeightUnion(t, h);//�������ڵ��������
		}
		if (count >= v - 1)break;//������Ϊ�ڵ�����һʱ���������
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