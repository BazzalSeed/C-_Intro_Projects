#pragma once
#include "bear.h"
#include "endangered.h"

class panda : public bear, public endangered

{
public:
	panda(std::string name);
	virtual ~panda();
	virtual void print() override;
	virtual int toes() override;
	void cuddle();
	virtual void react() override;

private:
	std::string nom;
};

