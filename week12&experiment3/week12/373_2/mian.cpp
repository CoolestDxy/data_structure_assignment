//Let G a directed,acyclic graph with n vertices. Assume that the vertices are numbered 0 through n-1 and that all edges are of the form 
//<i,j>,where i<j.Assume that the graph is aviliable as a set of adjacency lists and each edge has a length(with may be negative) associated with it.Write a C++ function to determine the length
//of the shortest paths from vertex 0 to  the remaining vertices.The complexity of your algorithm should be O(n+e),where e is the number
//of edges in the graph. Show that this is the case.
#include <iostream>
#include <list>
#include <stack>
#include <limits.h>
#define MAX 100
using namespace std;
// �ڽӱ�ڵ�
class AdjListNode
{
	int v;
	int weight;
public:
	AdjListNode(int _v, int _w) { v = _v;  weight = _w; }
	int getV() { return v; }
	int getWeight() { return weight; }
};
// ͼ
class Graph
{
	int V;    // �������
	list<AdjListNode> *adj;
	void topologicalSortRecall(int v, bool visited[], stack<int> &stk);
public:
	Graph(int V);
	void addEdge(int u, int v, int weight);
	void shortestPath(int s);
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<AdjListNode>[V];
}
void Graph::addEdge(int u, int v, int weight)
{
	AdjListNode node(v, weight);
	adj[u].push_back(node);
}
// �������򣬵ݹ���á�
void Graph::topologicalSortRecall(int v, bool visited[], stack<int> &stk)
{
	// ��ǵ�ǰ�ڵ��Ƿ��ʹ���
	visited[v] = true;
	list<AdjListNode>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		AdjListNode node = *i;
		if (!visited[node.getV()])
			topologicalSortRecall(node.getV(), visited, stk);
	}
	stk.push(v);
}
// �Ӹ�����Դ��s �ҳ��������������̾���.
void Graph::shortestPath(int s)
{
	stack<int> stk;
	int* dist=new int[V];
	//������ж���Ϊδ���ʹ���
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	// �������򣬽������stk��
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortRecall(i, visited, stk);
	// ��ʼ������
	for (int i = 0; i < V; i++)
		dist[i] = MAX;
	dist[s] = 0;
	// �������������˳���� ��������
	while (stk.empty() == false)
	{
		// ��������������һ������
		int u = stk.top();
		stk.pop();
		// �����������ڵĶ���
		list<AdjListNode>::iterator i;
		if (dist[u] != MAX)
		{
			for (i = adj[u].begin(); i != adj[u].end(); ++i)
				if (dist[i->getV()] > dist[u] + i->getWeight())
					dist[i->getV()] = dist[u] + i->getWeight();
		}
	}
	// ��ӡ���
	for (int i = 0; i < V; i++)
	{
		if (dist[i] == MAX)cout << "MAX ";
		else cout << dist[i] << " ";
	}
}
// ����
int main()
{
	Graph g(6);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 3);
	g.addEdge(1, 3, 6);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 4, 4);
	g.addEdge(2, 5, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 4, -1);
	g.addEdge(4, 5, -2);
	int s = 2;
	cout << "Following are shortest distances from source " << s << " \n";//max��ʾ�޷��ﵽ
	g.shortestPath(s);
	system("pause");
	return 0;
}
