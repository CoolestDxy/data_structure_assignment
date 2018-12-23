//Define an iterator class TopoIterator for iterating through the vertices of a directed acyclic graph in topological order
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
private:
	list<int>* HeadNodes;
	int *count;//保存顶点入度
	int n;//顶点个数
	int en;//边数

public:
	Graph(int vertices, int edges)
	{
		n = vertices; en = edges;
		HeadNodes = new list<int>[n];
		count = new int[n];
		for (int i = 0; i < n; i++)
		{
			count[i] = 0;
		}
	}
	int TopologicalIterator();
	void addedge(int,int);
};

void Graph::addedge(int t,int p)
{
	count[p]++;
	HeadNodes[t].push_back(p);
}

int Graph::TopologicalIterator()//迭代器
{
	for (int i = 0; i < n; i++)
	{
		if (count[i] == 0)
		{
			count[i] = -1;
			if (!HeadNodes[i].empty())
			{
				list<int>::const_iterator iter = HeadNodes[i].begin();
				if (iter == HeadNodes[i].end()) { return i; }
				while (*iter) {
					count[*iter]--;
				
						iter++;	
						if (iter == HeadNodes[i].end())break;
				}
			}
			return i;
		}
	}
	return -1;
}

int main()
{
	Graph g(4, 5);
	g.addedge(0, 1);
	g.addedge(1, 2);
	g.addedge(0, 2);
	g.addedge(2, 3);
	g.addedge(1, 3);
	for (int i = 0; i < 4; i++)
	{
		cout << g.TopologicalIterator();
	}
	system("pause");
	return 0;

}