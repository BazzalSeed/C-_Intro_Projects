// 332Studio_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "hello, world!" << endl;
	int size;
	string seed("seed");
	string yiqin ( "Yiqin");
	string team;
		team = seed + " " + ";" + " " + yiqin;
		cout << team << endl;
		size = team.length();
		cout << size << endl;
	return 0;
}

