#pragma once
template<class T>
class InorderIterator;
template<class T>
class PostorderIterator;
template<class T>
class PreorderIterator;
template<class T>
class LevelorderIterator;
template<class T>
class Tree;
void Bluidtree(Tree<char>&x);
template<class T>
class TreeNode
{
	friend class Tree<T>;
	friend class InorderIterator<T>;
	friend class PostorderIterator<T>;
	friend class PreorderIterator<T>;
	friend class LevelorderIterator<T>;
	friend void Bluidtree(Tree<char>&x);
public:
	TreeNode() { leftChild = rightChild = 0; }
	TreeNode(T x) {
		data = x;  leftChild = rightChild = 0;
	}
private:
	T data;
	TreeNode<T>*leftChild;
	TreeNode<T>*rightChild;
};
