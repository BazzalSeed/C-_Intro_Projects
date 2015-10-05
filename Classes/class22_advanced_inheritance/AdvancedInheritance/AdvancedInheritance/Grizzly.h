


#ifndef GRIZZLY_H
#define GRIZZLY_H


#include "Bear.h"
#include "Endangered.h"

#include <string>


using namespace std;
class Grizzly : public Bear, public Endangered {
public:
	Grizzly();
	virtual ~Grizzly();
	void growl();
	virtual void print();
	virtual int toes();
	virtual void react();
};

#endif