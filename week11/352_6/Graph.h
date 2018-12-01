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
	void OutputNewComponent(bool*visited, int c)
	{
		visited[c] = 1;
		cout << c << ' ';
		List<int>*Cur = HeadNotes + c;
		while (Cur->link != 0)
		{
			Cur = Cur->link;
			cout <<" "<<c<< "->" << Cur->data<<endl;
			if (visited[Cur->data] == 0)
			{
				OutputNewComponent(visited, Cur->data);
			}
		}
	}

	void Components()
	{
		bool *visited = new bool[n];
		for (int i = 0; i < n; i++)visited[i] = 0;
		for(int i=0;i<n;i++)
			if (!visited[i]) {
				OutputNewComponent(visited,i);
			}
		delete[]visited;
	}
private:
	List<int>*HeadNotes;
	int n;
};