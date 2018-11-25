#pragma once
#include"TreeNode.h"
#include"Tree.h"
#include"LinkedStack.h"
template<class T>
class Tree;
template<class T>
class TreeNode;
template<class T>
class LinkedStack;
template<class T>
class PreorderIterator
{
public:
	PreorderIterator(Tree<T> t) { CurrentNode = t.root; }
	T Next()//前序遍历迭代器，返回下一个遍历节点，难点在于区分左子树合适遍历完成，设立flag以区分，采用递归方式跳过空节点
	{
		T temp = 0;
		if (!s.IsEmpty() || CurrentNode)
		{
			if (flag == 1)
			{
				if (CurrentNode != 0)
				{
					s.Push(CurrentNode);
					temp = CurrentNode->data;
					CurrentNode = CurrentNode->leftChild;
					flag = 1;//左子树遍历时flag=1
				}
				else
				{
					flag = 0;//左子树遍历完flag=0
				}
			}
			if (flag == 0)//flag=0时右子树加一，右子树存在即输出
			{
				CurrentNode = s.gettop();
				s.Pop();
				CurrentNode = CurrentNode->rightChild;
				if (CurrentNode != 0)
				{
					s.Push(CurrentNode);
					temp = CurrentNode->data;
					CurrentNode = CurrentNode->leftChild;
				}
				else temp = Next();//此处采用递归来跳过遍历右子树时不存在的点，使每个next都有内容
				flag = 1;
			}
		}
		return temp;
	}
	void preorder()
	{
		T a = Next();
		while (a)
		{
			cout << a;
			a = Next();
		}
	}
private:
	LinkedStack<TreeNode<T>*>s;
	TreeNode<T>*CurrentNode;
	int flag = 1;
};