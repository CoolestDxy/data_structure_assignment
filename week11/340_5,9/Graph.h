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
	void DFS()//���õݹ�ķ��������η��ʸýڵ���Χδ�����ʹ��Ľڵ㣬���ýڵ���Χ�������ʹ����˻���һ�ڵ�����жϡ�
	{
		bool* visit = new bool[n];
		for (int i = 0; i < n; i++)
			visit[i] = 0;
		DFSrecursion(visit, 0);//��BFS���֣��ӵ������ڵ㿪ʼ����
	}
	void BFS()//���������������ͷ��ʼ���η����ӽڵ㲢���ڶ�β
	{
		bool*visited = new bool[n];
		for (int i = 0; i < n; i++)
			visited[i] = 0;
		queue<List<int>*>q;
		List<int>*Cur = HeadNotes;//�Ӹ��ڵ㿪ʼ����
		q.push(Cur);
		visited[Cur->data] = 1;
		while (!q.empty())
		{
			int i =q.front()->data;//ע�����ﲻ��ֱ�����Cur->data��ֵ���ڵ��ڽ������еĽڵ㲢����deadnote�еĽڵ㣬ֻ����������ͬ�ģ����Ϊ����
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