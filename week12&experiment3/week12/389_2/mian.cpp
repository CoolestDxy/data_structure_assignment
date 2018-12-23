//(a)For the AOE network of Figure 6.44 obtain the early,e(), and late,l(),start times for each activity.Use the forward-backward apporach
//(b)What is the earliest-time the project can finish?
//(c)Which activities are critical?
//(d)Is there any single activity whose speed-up would result in a reduction of the project length?
#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<iomanip>
using namespace std;

struct Edge
{
	int t,p;
	int value;
	Edge(int x, int y, int v)
	{
		t = x;
		p = y;
		value = v;
	}
};

struct Node//邻接链表节点
{
	int data;
	Node*link;
	bool ifhead;
	Node() { link = 0; ifhead = 1; };
	Node(int x) {
		data = x;
		link = 0;
		ifhead = 0;//判断是否为头节点
	}
	void addNode(int x)
	{
		Node*Cur = this;
		if (ifhead==1)//当第一个节点时！！
		{
			data = x;
			ifhead = 0;
			return;
		}
		while(Cur->link!=0)
		{
			Cur = Cur->link;
		}
		Cur->link = new Node(x);
	}
};

class Graph//采用邻接表
{
private:
	Node* HeadNodes;
	int *count;//保存顶点入度
	int *ee;//事件最早发生时间
	int *le;//事件最迟发生时间
	int *e;//活动最早发生时间
	int *l;//活动最迟发生时间
	int n;//顶点个数
	int en;//边数
	vector<Edge>edge;
public:
	Graph(const int vertices = 0,const int edges=0) :n(vertices),en(edges) {
		HeadNodes = new Node[n];
		count = new int[n];
		ee = new int[n];
		le = new int[n];
		e = new int[en];
		l = new int[en];
		for (int i = 0; i < n; i++)
		{
			count[i] = 0;
			ee[i] = 0;
			le[i] = 100;//最迟事件发生时间要设为最大值，当同一个事件涉及到多个最迟时间是要选最早的那个
		}
	}
	void TopologicalOrder();
	void addedge(int , int , int );
	void startTime();
	void LateTime();
	void crucialActivity();
};

void Graph::crucialActivity()//关键路径,b,c,d answer
{
	cout << endl << "b).the shortest finish time is :  " << ee[n - 1] << endl;//the shortest finish time is
	cout << endl<<"c).the crucialactivities are:" << endl;//the crucialactivities are
	for (int i = 0; i < en; i++)
	{
		if (e[i] == l[i])cout << i << ",";
	}
	
	cout << endl << "\nd).all the crucial activities' speed-up would result in a reduction of the project length " << endl;//all the crucial activities' speed-up would result in a reduction of the project length
}

void Graph::LateTime()
{
	/*for (int i = 0; i < n; i++)cout << le[i] << endl;*/
	for (int i = 0; i < en; i++)
	{
		l[i] = le[edge[i].p]-edge[i].value;
	}
	cout << "a).the latest time of every activity:" << endl;
	for (int i = 0; i < en; i++)
		cout <<setw(2)<< i + 1 << "  late time: " << l[i] << endl;
	cout << endl;
}

void Graph::startTime()
{

	for (int i = 0; i < en; i++)
	{
		e[i] = ee[edge[i].t] ;
	}
	cout << "a).the earilest time of every activity:" << endl;
	for (int i = 0; i < en; i++)
		cout << setw(2) << i+1 << "  start time: " << e[i] << endl;
	cout << endl;
}

void Graph::addedge(int t, int p, int v)
{
	count[p]++;
	HeadNodes[t].addNode(p);
	edge.push_back(Edge(t, p, v));
}

void Graph::TopologicalOrder()
{
	stack<int>topo;//拓扑排序的数组入栈，用于计算最迟事件发生时间
	cout << "topologicalOrder: " << endl;
	int top = -1;
	for(int i=0;i<n;i++)
		if (count[i] == 0) { count[i] = top; top = i; }//把当前的所有入度为零的顶点相连，并把top设置为最后的顶点
	for(int i=0;i<n;i++)
		if (top == -1) { cout << "network has a cycle" << endl; return; }//没有入度为零的点，则出现环
		else {
			int j = top; top = count[top];
			topo.push(j);
			cout << j << ",";//输出当前节点
			Node* Cur = &HeadNodes[j];//通过Cur对top节点的所有连接的节点进行遍历，将他们的count减1
			if (Cur->ifhead==1)continue;
			int k = Cur->data;
			int t;
			while (1)
			{ t=0;
				for (int i = 0; i < en; i++)
				{
					if (edge[i].t == j && edge[i].p==k)t = edge[i].value;
				}
				if (ee[k] < ee[j] + t)ee[k] = ee[j] + t;//计算更新事件最早发生时间
				count[k]--;
				if (count[k] == 0) { count[k] = top; top = k; }//把还未输出和新生成的所有顶点通过他们储存的下标相连，直到即将被输出的那个顶点，将top设为此节点
				if (Cur->link) 
				{ 
					Cur = Cur->link;
					k = Cur->data;
				}
				else break;
			}
		}
	cout << endl;
	int t=topo.top(),p;
	topo.pop();
	le[t] = ee[t];
	while (!topo.empty())//通过把压入栈的拓扑排序顶点出栈，用逆拓扑顺序求事件的最迟发生时间
	{
		t = topo.top();
		topo.pop();
		for (int i = 0; i < en; i++)
		{
			if (edge[i].t == t)
			{
				p = edge[i].p;
				if (le[t] > le[p] - edge[i].value)le[t] = le[p] - edge[i].value;//比较所有边取事件最小的为最迟发生时间，(le[tail]=le[point]-value)
			}
		}
	}
}

int main()
{
	Graph g(10,14);
	g.addedge(0, 1, 5);//ac0
	g.addedge(0, 2, 6);//ac1
	g.addedge(1, 3, 3);
	g.addedge(2, 3, 6);
	g.addedge(2, 4, 3);
	g.addedge(3, 4, 3);
	g.addedge(3, 5, 4);
	g.addedge(3, 6, 4);
	g.addedge(4, 6, 1);
	g.addedge(4, 7, 4);
	g.addedge(5, 9, 4);
	g.addedge(6, 8, 5);
	g.addedge(7, 8, 2);
	g.addedge(8, 9, 2);//ac13
	g.TopologicalOrder();
	g.startTime();
	g.LateTime();
	g.crucialActivity();
	system("pause");
}