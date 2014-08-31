#include <iostream>

#include "MyException.h"

template<class T>
class BinaryTreeNode
{
private:
	T data;
	BinaryTreeNode<T>* pLeftChild;
	BinaryTreeNode<T>* pRightChild;

public:
	BinaryTreeNode()
	{
		pLeftChild = 0;
		pRightChild = 0;
	}

	BinaryTreeNode(const T& e)
	{
		data = e;
		pLeftChild = 0;
		pRightChild = 0;
	}

	BinaryTreeNode(const T& e, BinaryTreeNode<T> *left, BinaryTreeNode<T>* right)
	{
		data = e;
		pLeftChild = left;
		pRightChild = right;
	}
};

template<class T>
class BinaryTree
{
public:
	BinaryTree()
	{
		root = 0;
	}

	~BinaryTree()
	{
	}

	bool isEmpty() const
	{
		if (root == 0)
			return true;
		else
			return false;
	}

	bool Root(T& x) const
	{
		if (root)
		{
			x = root->data;
			return true;
		}
		else
		{
			return false;
		}
	}

	void MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right)
	{
		root = new BinaryTreeNode<T>(element, left.root, right.root);
		left.root  = 0;
		right.root = 0;
	}

	void BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right)
	{
		if (root == 0)
			throw NoMemory();
		element = root->data;
		left.root = root->pLeftChild;
		right.root = root->pRightChild;

		delete root;
		root = 0;
	}

	void PreOrder(void(*visit)(BinaryTreeNode<T>* param), BinaryTreeNode<T>* node)
	{
		if (node)
		{
			visit(node);
			PreOrder(visit, node->pLeftChild);
			PreOrder(visit, node->pRightChild);
		}
	}

	void InOrder(void(*visit)(BinaryTreeNode<T>* param), BinaryTreeNode<T>* node)
	{
		if (node)
		{
			InOrder(visit, node->pLeftChild);
			visit(node);
			InOrder(visit, node->pRightChild);
		}
	}

	void PostOrder(void(*visit)(BinaryTreeNode<T>* param), BinaryTreeNode<T>* node)
	{
		if (node)
		{
			PostOrder(visit, node->pLeftChild);
			PostOrder(visit, node->pRightChild);
			visit(node);
		}
	}

private:
	BinaryTreeNode<T> *root;

};