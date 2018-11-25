#pragma once
#include<iostream>
#include<stack>
#include<queue>
#include"TreeNode.h"

using namespace std;


class Tree {

public:
	void deletetree()//删除所有节点，用层序遍历的方法进行递归
	{
		if (!s.empty()) {

			temp = s.front();
			s.pop();
			if (temp->leftChild != 0)
				s.push(temp->leftChild);
			if (temp->rightChild != 0)
				s.push(temp->rightChild);
			delete temp;
			temp = NULL;
			cout << "destructor called!" << endl;
			deletetree();
		}
		else return;
	}

	void Build()//新建一棵树
	{
		TreeNode*a = new TreeNode('+');
		TreeNode*b = new TreeNode('*');
		TreeNode*c = new TreeNode('-');
		TreeNode*e = new TreeNode('/');
		TreeNode*f = new TreeNode('A');
		TreeNode*g = new TreeNode('B');
		a->leftChild = b;
		a->rightChild = c;
		b->leftChild = e;
		b->rightChild = f;
		c->rightChild = g;
		root = a;
		s.push(root);
	}
	int countleaves()//用中序遍历来计算叶子数量
	{
		int count = 0;
		stack<TreeNode*>s;
		TreeNode*cur = root;
		while (!s.empty() || cur)
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->leftChild;
			}
			if (!s.empty())
			{
				cur = s.top();
				s.pop();
				if (cur->rightChild == 0)
					count++;
				cur = cur->rightChild;
			}
		}
		return count;
	}
private:
	TreeNode*root;
	queue<TreeNode*>s;
	TreeNode* temp;
};