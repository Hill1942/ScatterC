#pragma once


#include <exception>
#include <iostream>

class OutOfBound: public std::exception
{
public:
	OutOfBound()
	{
		std::cout << "An Exception has Occured: Out Of Bound" << std::endl;
	}
};

class NoMemory: public std::exception
{
public:
	NoMemory()
	{
		std::cout << "An Exception has Occured: No Memory" << std::endl;
	}
};