#pragma once

#include <iostream>

#include "MyException.h"


template<class T>
class Stack
{
private:
	T* elements;
	int top;
	int maxTop;
public:
	Stack(int size)
	{
		elements = new T[size];
		top = -1;
		maxTop = size - 1;
	}
	~Stack()
	{
		delete[] elements;
	}

public:
	bool isEmpty() const
	{
		if (top == -1)
			return true;
		else
			return false;
	}

	bool isFull() const
	{
		if (top == maxTop)
			return true;
		else
			return false;
	}

	T Top() const
	{
		return elements[top];

	}

	int Size() const
	{
		return maxTop + 1;
	}

	Stack<T>& Push(const T& x)
	{
		if (isFull())
			throw NoMemory();
		top++;
		elements[top] = x;
		
		return *this;
	}

	Stack<T>& Pop()
	{
		if (isEmpty())
		{
			throw OutOfBound();
		}
		else
		{
			top--;
		}
		return *this;
	}
};