// CSE332_Associate Container1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <iterator>
#include <numeric>
using namespace std;



bool compare(const string  &  s1, const  string & s2){

		if (s1.size() != s2.size()){
			return s1.size() < s2.size();
		}

		return s1[0] < s2[0];


	}


int main(int argc, char* argv[])
{

//Question 2
	/*
	set<string> myset;
	

	auto it = std::inserter(myset, myset.begin());

	copy(argv,argv+argc, it);
	ostream_iterator<string> print_iter(cout, " ");
	copy( myset.begin(), myset.end(),print_iter);

	*/
//Question 3
//They are the same for some reason

	set<string, decltype(compare)*> myset1;

	/*
	set<string>::iterator iterate1 = myset1.begin();
	copy(argv, argv + argc, inserter(myset1, iterate1));
	ostream_iterator<string> print_iter1(cout, " ");
	copy(myset1.begin(), myset1.end(), print_iter1);
	
	*/
	/*
	set<char*> myset;

	set<char*>::iterator iterate2 = myset.begin();
	copy(argv, argv + argc, inserter(myset, iterate2));
	ostream_iterator<char*> print_iter(cout, " ");
	copy(myset.begin(), myset.end(), print_iter);
	
	//Question 4, no matter what order i put in, the output stays the same. Because set is a dick and maintains its own order

	//Question 5  now it's different, set<char*> messed up the uniquness feature because pointers compare value by address. fk that shit.
	
	//Question 6
	*/
	
	set<string>::iterator iterate1 = myset1.begin();
	copy(argv, argv + argc, inserter(myset1, iterate1));
	ostream_iterator<string> print_iter1(cout, " ");
	
	copy(myset1.begin(), myset1.end(), print_iter1);
	
	
	return 0;
}

//Qustion 6
