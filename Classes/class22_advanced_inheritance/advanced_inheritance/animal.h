#pragma once
#include <iostream>





class animal
{
public:
	animal();
	virtual ~animal();
	virtual void print() = 0;
	virtual void react() = 0;
};

