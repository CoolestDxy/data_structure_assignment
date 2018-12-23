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

struct Node//�ڽ�����ڵ�
{
	int data;
	Node*link;
	bool ifhead;
	Node() { link = 0; ifhead = 1; };
	Node(int x) {
		data = x;
		link = 0;
		ifhead = 0;//�ж��Ƿ�Ϊͷ�ڵ�
	}
	void addNode(int x)
	{
		Node*Cur = this;
		if (ifhead==1)//����һ���ڵ�ʱ����
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

class Graph//�����ڽӱ�
{
private:
	Node* HeadNodes;
	int *count;//���涥�����
	int *ee;//�¼����緢��ʱ��
	int *le;//�¼���ٷ���ʱ��
	int *e;//����緢��ʱ��
	int *l;//���ٷ���ʱ��
	int n;//�������
	int en;//����
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
			le[i] = 100;//����¼�����ʱ��Ҫ��Ϊ���ֵ����ͬһ���¼��漰��������ʱ����Ҫѡ������Ǹ�
		}
	}
	void TopologicalOrder();
	void addedge(int , int , int );
	void startTime();
	void LateTime();
	void crucialActivity();
};

void Graph::crucialActivity()//�ؼ�·��,b,c,d answer
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
	stack<int>topo;//���������������ջ�����ڼ�������¼�����ʱ��
	cout << "topologicalOrder: " << endl;
	int top = -1;
	for(int i=0;i<n;i++)
		if (count[i] == 0) { count[i] = top; top = i; }//�ѵ�ǰ���������Ϊ��Ķ�������������top����Ϊ���Ķ���
	for(int i=0;i<n;i++)
		if (top == -1) { cout << "network has a cycle" << endl; return; }//û�����Ϊ��ĵ㣬����ֻ�
		else {
			int j = top; top = count[top];
			topo.push(j);
			cout << j << ",";//�����ǰ�ڵ�
			Node* Cur = &HeadNodes[j];//ͨ��Cur��top�ڵ���������ӵĽڵ���б����������ǵ�count��1
			if (Cur->ifhead==1)continue;
			int k = Cur->data;
			int t;
			while (1)
			{ t=0;
				for (int i = 0; i < en; i++)
				{
					if (edge[i].t == j && edge[i].p==k)t = edge[i].value;
				}
				if (ee[k] < ee[j] + t)ee[k] = ee[j] + t;//��������¼����緢��ʱ��
				count[k]--;
				if (count[k] == 0) { count[k] = top; top = k; }//�ѻ�δ����������ɵ����ж���ͨ�����Ǵ�����±�������ֱ��������������Ǹ����㣬��top��Ϊ�˽ڵ�
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
	while (!topo.empty())//ͨ����ѹ��ջ���������򶥵��ջ����������˳�����¼�����ٷ���ʱ��
	{
		t = topo.top();
		topo.pop();
		for (int i = 0; i < en; i++)
		{
			if (edge[i].t == t)
			{
				p = edge[i].p;
				if (le[t] > le[p] - edge[i].value)le[t] = le[p] - edge[i].value;//�Ƚ����б�ȡ�¼���С��Ϊ��ٷ���ʱ�䣬(le[tail]=le[point]-value)
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