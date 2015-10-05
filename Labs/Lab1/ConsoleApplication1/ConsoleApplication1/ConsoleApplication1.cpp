// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
int _tmain(int argc, _TCHAR* argv[])
{
	int a = 3;
	int * p = &a;
	using namespace std;
	cout <<* p << endl;
	return 0;
}

