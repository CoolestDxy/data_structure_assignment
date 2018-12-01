#pragma once
#include<iostream>
#include<queue>
#include"List.h"
using namespace std;
class Graph {
public:
	Graph(const int vertices = 0) :n(vertices) {
		HeadNotes = new List<int>[n];
	}
	void addedge(int tail, int head)
	{
		List<int>*Cur;
		bool flagt = 0, flagh = 0;
		for (int i = 0; i < n; i++)
		{
			if (tail == i)
			{
				Cur = HeadNotes + i;
				while (Cur->link != 0)
					Cur = Cur->link;
				Cur->link = new List<int>(head);
				flagt = 1;
			}
			if (head == i)
			{
				Cur = HeadNotes + i;
				while (Cur->link != 0)
					Cur = Cur->link;
				Cur->link = new List<int>(tail);
				flagh = 1;
			}
		}if (flagt == 0)cout << "the tail does not exit!" << endl;
		if (flagh == 0)cout << "the head does not exit!" << endl;
	}
	void DFSrecursion(bool*visit, int c)
	{
		visit[c] = 1;
		cout << c << ' ';
		List<int>*Cur = HeadNotes + c;
		while (Cur->link != 0)
		{
			Cur = Cur->link;
			if(visit[Cur->data]==0)
				DFSrecursion(visit, Cur->data);
		}
	}
	void DFS()//采用递归的方法，依次访问该节点周围未被访问过的节点，当该节点周围都被访问过则退回上一节点继续判断。
	{
		bool* visit = new bool[n];
		for (int i = 0; i < n; i++)
			visit[i] = 0;
		DFSrecursion(visit, 0);//与BFS区分，从第三个节点开始遍历
	}
	void BFS()//广度优先搜索，从头开始依次访问子节点并置于队尾
	{
		bool*visited = new bool[n];
		for (int i = 0; i < n; i++)
			visited[i] = 0;
		queue<List<int>*>q;
		List<int>*Cur = HeadNotes;//从根节点开始遍历
		q.push(Cur);
		visited[Cur->data] = 1;
		while (!q.empty())
		{
			int i =q.front()->data;//注意这里不能直接输出Cur->data的值，节点邻接链表中的节点并不是deadnote中的节点，只有坐标是相同的，输出为坐标
			Cur = HeadNotes + i;
			cout <<i<< ' ';
			q.pop();
			while (Cur!= 0)
			{
				if (visited[Cur->data] == 0)
				{
					q.push(Cur);
					visited[Cur->data] = 1;
				}
				Cur = Cur->link;
			}
		}
		cout << endl;
	}
	void print()
	{
		List<int>*Cur;
		for (int i = 0; i < n; i++)
		{
			Cur = HeadNotes + i;
			Cur = Cur->link;
			cout << "tail: " << i << "  heads: ";
			while (Cur != 0)
			{
				cout << Cur->data << " ";
				Cur = Cur->link;
			}
			cout << endl;
		}
	}
	void test()
	{
		List<int>*temp = HeadNotes+1;
		while (temp != 0)
		{
			cout << temp->data<<' ';
			temp = temp->link;
		}
	}
private:
	List<int>*HeadNotes;
	int n;
};