// CSE_Copy_Control.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Wrapper.h"

int main(int argc, char* argv[])
{
	Wrapper w2;
	Wrapper w1 = Wrapper (w2);
	Wrapper w3 = Wrapper(move(w2));
	Wrapper w4;
	cout << "------------------" << endl;
	w4 = w2;
	w4 = move(w2);
	//Wrapper w2;
	//w2 = w1;

	

	
	return 0;
}

