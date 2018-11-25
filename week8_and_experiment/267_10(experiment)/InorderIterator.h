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
class InorderIterator {
public:
	InorderIterator(Tree<T> t) { CurrentNode = t.root; }
	T*Next()//�����������������ȡ��һ�������ڵ㣬�Ӹ��ڵ���Ѱ�ӽڵ�
	{
		while (CurrentNode)
		{
			s.Push(CurrentNode);
			CurrentNode = CurrentNode->leftChild;
		}
		if (!s.IsEmpty())
		{
			CurrentNode = s.Pop();
			T &temp = CurrentNode->data;
			CurrentNode = CurrentNode->rightChild;
			return &temp;
		}
		else return 0;
	}
	void Inorder()
	{
		T* a = Next();
		while (a)
		{
			cout << a;
			a = Next();
		}
	}
private:
	LinkedStack<TreeNode<T>*>s;
	TreeNode<T>*CurrentNode;
};
