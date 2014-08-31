#pragma once

#include <iostream>
#include "MyException.h"



template<class T>
class ChainNode
{
public:
	T data;
	ChainNode* plink;
};

template<class T>
class Chain
{
private:
	ChainNode<T>* first;

public:
	Chain()
	{
		first = 0;
	}
	~Chain()
	{
		ChainNode<T>* next;
		while (first)
		{
			next = first->plink;
			delete first;
			first = next;
		}
	}

public:
	bool isEmpty() const
	{
		if (first == 0)
			return true;
		else
			return false;
	}

	int Length() const
	{
		int len = 0;
		ChainNode<T>* current = first;
		while (current)
		{
			len++;
			current = current->plink;
		}
		return len;
	}

	bool Find(int k, T& x) const
	{
		if (k < 0)
			return false;
		ChainNode<T>* current = first;
		int index = 0;
		while (index < k && current)
		{
			current = current->plink;
			index++;
		}
		if (current)
		{
			x = current->data;
			return true;
		}
		else
		{
			return false;
		}
	}

	int Search(const T& x)
	{
		int index = 0;
		ChainNode<T>* current = first;
		while (current && current->data != x)
		{
			current = current->plink;
			index++;
		}
		if (current)
			return index;
		return -1;
	}

	Chain<T>& Insert(int k, const T& x)
	{
		if (k < 0)
			throw OutOfBound();
		ChainNode<T>* node = new ChainNode<T>;
		node->data = x;
		if (k == 0)
		{
			node->plink = first;
			first = node;
		}
		else
		{
			ChainNode<T>* p = first;
			for (int i = 0; i < k - 1 && p; i++)
			{
				p = p->plink;
			}
			if (p == NULL || p->plink == NULL)
				throw OutOfBound();
			node->plink = p->plink;
			p->plink = node;
		}
		return *this;
	}

	Chain<T>& Delete(int k, T& x)
	{
		ChainNode<T>* p = first;
		if (k < 0 || p == NULL)
			throw OutOfBound();
		
		if (k == 0)
			first = p->plink;
		else
		{
			for (int i = 0; i < k - 1 && p; i++)
			{
				p = p->plink;
			}
			if (p == NULL || p->plink == NULL)
				throw OutOfBound();	
			else
			{			
				ChainNode<T>* prev = p;
				p = prev->plink;
				prev->plink = p->plink;
			}
		}
		x = p->data;
		delete p;
		return *this;
	}

	Chain<T>& Append(const T& x)
	{
		ChainNode<T>* node = new ChainNode<T>;
		node->data = x;
		if (first == NULL)
		{
			first = node;
			node->plink = NULL;
		} 
		else
		{
			ChainNode<T>* current = first;
			while (current->plink)
			{
				current = current->plink;
			}
			current->plink = node;
			node->plink = NULL;
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, Chain<T>& chain)
	{
		if (chain.first == NULL)
			out << "No Data";
		else
		{
			ChainNode<T>* current = chain.first;
			while (current)
			{
				out << current->data << " ";
				current = current->plink;
			}
		}
		return out;
	}
};
