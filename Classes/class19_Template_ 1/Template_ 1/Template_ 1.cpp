// Template_ 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
# include "template.h"
# include "template_struct.h"
# include <vector>
# include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	//Question 2
	/*
	int jing[] = { 1, 2, 3, 4 };
	vector<int> v = { 1, 2, 3, 4 };

	int range = sizeof(jing) / sizeof(int);
	
	size_t range_v;
	size_t range_jing;
	range_v = counter(v.begin(), v.end());
	range_jing = counter(jing, jing + range);
	cout << "range for jing: " << range_jing << endl;
	cout << "range for v: " << range_v << endl;
	*/
	//Question 3
	/*
	int jing = 1;
	char seed = '1';
	myS<int> s1(jing);
	myS<char>s2(seed);
	cout << "size of jing: " << sizeof(jing) << endl;

	cout << "size of seed: " << sizeof(seed) << endl; 
	cout << "size of s1: " << sizeof(s1) << endl;
	cout << "size of s2: " << sizeof(s2) << endl;
	*/

	//Question 4  , 5 

	/*
	int jing = 1;
	char seed = 'A';

	myS<int> s1(jing);
	myS<char>s2(seed);
	myS<int>s3(seed);
	cout << s1 << endl;
	cout << s2 << endl;

	cout << "--------operator overloading result----------" << endl;
	
	cout << (s1 < s3) << endl;
	cout << (s1 == s3) << endl;
	*/

	//Question 6
	myS<int> s1();
	myS<int> s2();
	//cout << s1 << endl;


	return 0;

}

