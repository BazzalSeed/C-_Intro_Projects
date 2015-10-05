// algorithm2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <deque>
#include <forward_list>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>

using namespace std;

bool rankFunction(int num1, int num2);

struct myStruct{
public:
	bool operator()(int num1, int num2){
		return num1 > num2;
	}
};




int main(int argc, char* argv[])
{
	deque<int> container1;
	forward_list<int> container2;
	vector<int> container3;

	for (int i = 1; i <= 5; i++){
		container1.push_back(i);
		container2.push_front(i);
		container3.push_back(i);
	}

	deque<int>::iterator iter1 = container1.begin();
	forward_list<int>::iterator iter2 = container2.begin();
	vector<int>::iterator iter3 = container3.begin();


	//problem 2
	//Explain: random access container provides random index so that we can use pointer arithmetic to find
	//a particular position. But for some container that only provides sequential access, we can only
	//increment the position one by one to reach the particular position
	iter1 += 2;
	cout << "deque 2nd position: " << *iter1 << endl;
	iter2++;
	iter2++;
	cout << "forwardlist 2nd position: " << *iter2 << endl;
	iter3 += 2;
	cout << "vector 2nd position: " << *iter3 << endl;

	//problem 3
	//Explain: to get empty range, just use the same iterator in the copy() algorithm
	//to get nonempty range, two iterator positions passed in should be different
	ostream_iterator<int> osIter(cout, " ");
	cout << "Empty range in deque: " << endl;
	copy(iter1, iter1, osIter);
	cout << "Nonempty range in deque: " << endl;
	copy(iter1, iter1 + 2, osIter);
	cout << "\n" << endl;

	cout << "Empty range in list: " << endl;
	copy(iter2, iter2, osIter);
	cout << "Nonempty range in list: " << endl;
	iter2++;
	iter2++;
	copy(iter2, iter2, osIter);
	cout << "\n" << endl;

	cout << "Empty range in vector: " << endl;
	copy(iter3, iter3, osIter);
	cout << "Nonempty range in vector: " << endl;
	copy(iter3, iter3 + 2, osIter);
	cout << "\n" << endl;

	//problem 4
	int arr[] = { -2, 19, 80, -47, 80, 80, -2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int *start = arr;
	int *end = start + size;
	ostream_iterator<int> arrIter(cout, " ");
	cout << "Array before sorted: " << endl;
	copy(start, end, arrIter);
	cout << "\n" << endl;

	//problem 5
	cout << "Array after sorted: " << endl;
	greater<int> g;
	sort(start, end, g);
	copy(start, end, arrIter);
	cout << "\n" << endl;

	cout << "Array after sorted(according to rank function)" << endl;
	sort(start, end, rankFunction);
	copy(start, end, arrIter);
	cout << "\n" << endl;


	//problem 6
	myStruct cool;
	cout << "Array after sorted(according to struct)" << endl;
	sort(start, end, cool);
	copy(start, end, arrIter);





	
	return 0;
}


bool rankFunction(int num1, int num2){
	return num1 > num2;
}
