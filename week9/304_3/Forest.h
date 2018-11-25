#pragma once
#include<queue>
#include"Tree.h"
using namespace std;

class Forest
{
public:
	void addtree(Tree&x)
	{
		roots.push(x);
	}
	void forestPreorder()
	{
		while (!roots.empty())
		{
			roots.front().preorder();
			roots.pop();
		}
	}
private:
	queue<Tree>roots;
};