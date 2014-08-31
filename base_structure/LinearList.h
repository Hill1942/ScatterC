#pragma once

#include <iostream>

#include "MyException.h"

template<class T>
class LinearList
{
private:
	T*  elements;
	int length;
	int maxSize;

public:
	LinearList(int maxSize = 10)
	{
		this->maxSize = maxSize;
		elements = new T[maxSize];
		length = 0;
	}
	~LinearList(void)
	{
		delete[] elements;
	}


public:
	bool IsEmpty() const
	{
		if (length == 0)
			return true;
		else
			return false;
	}

	int  Length() const
	{
		return length;
	}

	bool Find(int k, T& x) const
	{
		if (k < 0 || k > length - 1)
			return false;
		x = elements[k];
		return true;
	}

	int  Search(const T&x) const
	{
		for (int i = 0; i < length; i++)
		{
			if (elements[i] == x)
				return i;
		}
		return -1;
	}

	LinearList<T>& Delete(int k, T& x)
	{
		if (k < 0 || k > length - 1)
		{
			throw OutOfBound();
		}
		else
		{
			x = elements[k];
			for (int i = k; i < length - 1; i++)
			{	
				elements[i] = elements[i + 1];
			}
			length--;
			return *this;
		}	
	}

	LinearList<T>& Insert(int k, const T& x)
	{
		if (length == maxSize)
			throw NoMemory();
		if (k < 0 || k > length)
			throw OutOfBound();

		for (int i = k; i < length; i++)
		{
			elements[i + 1] = elements[i];
		}
		elements[k] = x;
		length++;

		return *this;
	}

	LinearList<T>& Append(const T& x)
	{
		if (length == maxSize)
			throw NoMemory();
		elements[length] = x;
		length++;

		return *this;
	}
	
	friend std::ostream& operator<<(std::ostream& out, LinearList<T>& x)
	{
		for (int i = 0; i < x.length; i++)
		{
			out << x.elements[i] << " ";
		}
		
		return out;
	}
};








