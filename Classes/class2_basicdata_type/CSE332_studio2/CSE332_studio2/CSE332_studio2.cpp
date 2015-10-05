// CSE332_studio2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	
	cout << argv[1] << endl;
	cout << *argv << endl;
	/*
    auto *p = argv;
	for (; p&&(*p != '\0'); p++){
		cout << *p << endl;
	}
	*/
	return 0;
}

