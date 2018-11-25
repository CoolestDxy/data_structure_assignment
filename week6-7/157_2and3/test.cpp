//p157-2:find the maximam path length from start to finish 
//p157-3:recusion version of path()
#include <iostream>
#include "Stack.h"
#include"Stack.cpp"
using namespace std;

struct offset {
	offset(int x, int y) {
		a = x; b = y;
	}
	int a, b;
};
static offset moved[8] = {offset(-1,0),offset(-1,+1),offset(0,1),offset(1,1),offset(1,0),offset(1,-1),offset(0,-1),offset(-1,-1)};
int maze[][17] = {
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1},
{1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1},
{1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1},
{1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1},
{1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1},
{1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
{1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
{1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
{1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1},
{1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1},
{1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1},
{1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
int length;
int mark[12][15];
void path(int,int);
void recupath(int, int, int, int, int, items&, Stack<items>&);//the recursion of path()
void lpath(int, int, int, int, int, Stack<items>&);//the longest path 
int main()
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 15; j++)
			mark[i][j] = 0;
	int most[10];
	mark[0][0] = 1;
	Stack<items>stack1(12 * 15), stack2(12 * 15); //No2.the longest path of length
	lpath(12, 15, 1, 1, 0, stack2);
	cout << "the longest path of maze is: "<<endl<<length;
	items temp;
	temp.x = 1; temp.y = 1; temp.dir = 2;
	stack1.Add(temp);
	int i, j, d;
	cout << endl<<"the recursion of path():" << endl;
	recupath(12, 15, 1, 1, 2, temp, stack1);//No3. the recursion of path,the compelxity of the function is O(n);
	
	system("pause");
}
void recupath(int m, int p ,int i,int j,int d,items& temp,Stack<items>&stack)
{
	if (!stack.IsEmpty()) {
		if (d < 8)
		{
			int g = i + moved[d].a; int h = j + moved[d].b;
			if ((g == m) && (h == p)) {
				cout << stack;
				cout << i << " " << j << endl;
				cout << m << " " << p << endl;
				return;
			}
			if ((!maze[g][h]) && (!mark[g - 1][h - 1]))
			{
				mark[g - 1][h - 1] = 1;
				temp.x = i; temp.y = j; temp.dir = d + 1;
				stack.Add(temp);
				i = g; j = h; d = 0;
			}
			else d++;
		}
		else {
			temp = *stack.Delete(temp);
			i = temp.x; j = temp.y;  d = temp.dir;
		}
		recupath(m, p, i, j, d, temp, stack);
	}
	else {
		cout << "no path!" << endl;
		return;
	}
}
void path(int m, int p)
{
	mark[0][0] = 1;
	Stack<items>stack(m*p);
	items temp;
	temp.x = 1; temp.y = 1; temp.dir = 2;
	stack.Add(temp);
	while (!stack.IsEmpty())
	{
		temp = *stack.Delete(temp);
		 int i = temp.x; int j = temp.y; int d = temp.dir;
		while (d < 8)
		{

			int g = i + moved[d].a; int h = j + moved[d].b;
			if ((g == m) && (h == p)) {
				cout << stack;
				cout << i << " " << j << endl;
				cout << m << " " << p << endl;
				return;
			}
			if ((!maze[g][h]) && (!mark[g - 1][h - 1]))
			{
				mark[g - 1][h - 1] = 1;
				temp.x = i; temp.y = j; temp.dir = d + 1;
				stack.Add(temp);
				i = g; j = h; d = 0;
			}
			else d++;
		}
	}
	cout << "no path" << endl;
}

void lpath(int endx,int endy,int x,int y,int step,Stack<items>&stack)
{
	int tx, ty;
	if (x == endx && y == endy)
	{
		length = step;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		tx = x + moved[i].a;
		ty = y + moved[i].b;
		if (maze[tx][ty] == 0 && mark[tx - 1][ty - 1] == 0)
		{
			stack.Add(items(tx, ty, i));
			step++;
			mark[tx-1][ty-1] = 1;
			lpath(endx, endy, tx, ty, step, stack);
			stack.Delete();
			step++;
			mark[tx - 1][ty - 1] = 0;
		}
	}
	return;
}