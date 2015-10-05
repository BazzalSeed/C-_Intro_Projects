

#ifndef ANIMAL_H
#define ANIMAL_H


class Animal{
public:
	Animal();
	virtual ~Animal();
	virtual void print() = 0;
	virtual void react() = 0;
};

#endif