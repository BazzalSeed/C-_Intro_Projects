
#ifndef BEAR_H
#define BEAR_H

#include "Animal.h"


class Bear : public Animal{
public:
	Bear();
	virtual ~Bear();
	virtual int toes() = 0;
};


#endif