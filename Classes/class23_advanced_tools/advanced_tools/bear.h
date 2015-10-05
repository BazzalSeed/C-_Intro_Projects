#pragma once
#include "animal.h"


class bear : public animal
{
public:
	bear();
	virtual ~bear();
	virtual int toes() = 0;

};

