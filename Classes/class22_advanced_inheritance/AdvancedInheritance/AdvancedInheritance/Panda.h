


#ifndef PANDA_H
#define PANDA_H

#include "Bear.h"
#include "Endangered.h"
#include <string>

using namespace std;

class Panda : public Bear, public Endangered{
public:
	string name;
	Panda(string);
	void cuddle();
	virtual ~Panda();
	virtual void print();
	virtual int toes();
	virtual void react();
};

#endif