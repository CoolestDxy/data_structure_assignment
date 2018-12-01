#pragma once
#include<iostream>
#include"List.h"
using namespace std;
class Graph {
public:
	Graph(const int vertices = 0) :n(vertices) {
		HeadNotes = new List<int>[n];
	}
	void input() {
		int tail, head;
		List<int>*Cur;
		cout << "input the tail and head:" << endl;
		cin >> tail >> head;
		while (tail != -1)
		{
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
			cin >> tail >> head;
		}
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
private:
	List<int>*HeadNotes;
	int n;
};