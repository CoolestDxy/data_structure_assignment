#include "Bug.h"
#include<iostream>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip> 
using namespace std;

int Bug::imove[8] = { -1,0,1,1,1,0,-1,-1 };
int Bug::jmove[8] = { 1,1,1,0,-1,-1,-1,0 };

Bug::Bug(int a,int b)
{
	if (a <= 2 || a > 40 || b < 2 || b>20)
		cout << "out of the range!" << endl;
	srand(time(0));
	n = a; m = b,step=0;
	count = new int*[n];
	for (int i = 0; i < n; i++)
	{
		count[i] = new int[m];
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			 count[j][i]=0;
		}
	}
}


void Bug::print()
{
	cout << "the steps: " << step<< endl;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			cout <<setw(3)<< count[j][i];
		}cout << endl;
	}
}

void Bug::stimulate(int x,int y)
{

	count[x][y]++; step++;
	bool flag = 0;
	for(int j=0;j<n;j++)
		for (int i = 0; i < m; i++)
		{
			if (count[j][i] == 0)flag = 1;
		}
	while (flag == 1)
	{
		flag = 0;
		count[x][y]++;
		for (int j = 0; j < n; j++)
			for (int i = 0; i < m; i++)
			{
				if (count[j][i] == 0)flag = 1;
			}
		int t = rand() % 8;
		while (x + imove[t] < 0 || x + imove[t] >= n || y + jmove[t] < 0 || y + jmove[t] >= m)
			t = rand() % 8;
		x += imove[t]; y += jmove[t]; step++;
		if (step == 50000) {
			cout << "over 50000steps!!" << endl;
			return;
		}
	}
}

Bug::~Bug()
{
}
