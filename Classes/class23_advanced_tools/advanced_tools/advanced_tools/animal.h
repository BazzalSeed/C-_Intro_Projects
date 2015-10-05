#pragma once


#include <iostream>
#include <string>
#include <new>




class animal
{
public:
	animal();
	virtual ~animal();
	virtual void print() = 0;
	virtual void react() = 0;
	void *operator new(size_t size)
	{
		if (void * address = malloc(size))
		{
			std::cout << address << std::endl;
			return address;
		}
		else
		{
			throw std::bad_alloc();
		}
	}

	void operator delete(void * add)
	{
		std::cout << add << std::endl;
		free(add);
	}

};

