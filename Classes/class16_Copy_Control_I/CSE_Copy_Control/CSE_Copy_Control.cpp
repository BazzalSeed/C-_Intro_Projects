// CSE_Copy_Control.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Wrapper.h"

int main(int argc, char* argv[])
{
	Wrapper w1;
	Wrapper w2 = Wrapper(w1);
	return 0;
}

