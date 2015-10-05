#pragma once
#include "bear.h"
#include "endangered.h"

class grizzly : public bear, public endangered
{
public:
	grizzly();
	virtual ~grizzly();
	virtual void print() override;
	virtual int toes() override;
	void growl();
	virtual void react() override;
};

