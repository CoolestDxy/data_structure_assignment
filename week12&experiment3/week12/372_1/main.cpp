//let T be a tree with root v.The edges of T are undirected.Each edge in T has a nonnegative lengh. Write a C++ function to determine 
//the length of the shortest paths from v to the remaining vertices of T.Your function should have complexity O(n),where n is the number of vertices in T¡£
#include<iostream>
using namespace std;

#define num 6

int tree[num];
int matrix[num][num];
int dist[num];

void init()
{
	for (int i = 0; i < num; i++)
	{
		tree[i] = -1;
	}
	for(int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
		{
			matrix[i][j] = -1;
			if(i==j)matrix[i][j] = 0;
		}

}

void addedge(int tail, int point, int value)
{
	tree[point] = tail;
	matrix[tail][point] = value;
}

int shortestPath(int x)
{
	int l = 0, last = x;
	while (tree[x] != -1)
	{
		l += matrix[x][last];
		last = x;
		x = tree[x];
	}
	l += matrix[x][last];
	return l;
}

int main()
{
	init();
	addedge(0, 1, 10);
	addedge(0, 2, 5);
	addedge(1, 3, 7);
	addedge(3, 4, 8);
	addedge(3, 5, 9);
	for (int i = 0; i < num; i++)
	{
		cout << "0->" << i << ": " << shortestPath(i) << endl;
	}

	system("pause");
}
