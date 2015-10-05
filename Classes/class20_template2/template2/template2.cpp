// template2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Iter.h"
#include <iostream>
#include <list>

using namespace std;

int main(int argc, char* argv[])
{
	int arr[] = { 1, 2, 3, 4 };
	list<int> l = { 1, 2, 3, 4 };
	char c[] = { 'a', 'b', 'c' ,'d'};


	size_t n = sizeof(arr) / sizeof(int);
	cout << "size of array: " << counting(arr, arr + n) << endl;
	cout << "size of char array: " << counting1(c, c + n) << endl;
	

	return 0;
}

