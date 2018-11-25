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
	T*Next()//中序遍历迭代器，获取下一个遍历节点，从根节点找寻子节点
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
