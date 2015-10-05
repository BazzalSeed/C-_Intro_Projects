// SequentialContainer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iterator>

using namespace std;




int main(int argc, char* argv[])
{
	//problem 2
	//vector: push back and pop back
	//deque: push back, pop back, push front, pop front
	//list: push back, pop back, push front, pop front
	//forward_list: push front, pop front

	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.pop_back();
	vec.pop_back();


	deque<int> dq;
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	dq.pop_back();
	dq.pop_back();
	dq.push_front(1);
	dq.pop_front();

	
	list<int> l;
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.pop_front();
	l.pop_front();
	l.push_back(1);
	l.pop_back();


	forward_list<int> fl;
	fl.push_front(1);
	fl.push_front(2);
	fl.push_front(3);
	fl.pop_front();
	fl.pop_front();
	
	//problem 3
	//explain: push_front is to insert element at the front of container
	//push_back is to insert element at the back of container
	vector<int> myVec;
	deque<int> myDeque;
	list<int> myList;
	forward_list<int> myForwardList;

	for (int j = 1; j <= 3; j++){
		myVec.push_back(j);
	}


	for (int i = 3; i >= 1; i--){
		myDeque.push_front(i);
		myList.push_front(i);
		myForwardList.push_front(i);
	}

	vector<int>::iterator vIter = myVec.begin();
	deque<int>::iterator qIter = myDeque.begin();
	list<int>::iterator lIter = myList.begin();
	forward_list<int>::iterator flIter = myForwardList.begin();


   cout << "vector contents" << endl;
	for (auto pos = vIter; pos != myVec.end(); pos++){
		cout << *pos;
	}
	cout << endl;
	
	cout << "deque contents" << endl;
	for (auto pos = qIter; pos != myDeque.end(); pos++){
		cout << *pos;
	}
	cout << endl;


	cout << "list contents" << endl;
	for (auto pos = lIter; pos != myList.end(); pos++){
		cout << *pos;
	}
	cout << endl;


	cout << "forward_list contents" << endl;
	for (auto pos = flIter; pos != myForwardList.end(); pos++){
		cout << *pos;
	}
	cout << endl;


	//problem 4
	//explain: declare the iterator as vector<int>::const_iterator  vIter = vec.begin();
	passContainer(myVec);


	//problem 5
	//explain: random access containers are vector and deque, others are not
	cout << "vector contents" << endl;
	for (unsigned int k = 0; k < myVec.size(); k++){
		cout << myVec[k];
	}


	cout << "deque contents" << endl;
	for (unsigned int k = 0; k < myDeque.size(); k++){
		cout << myDeque[k];
	}

	/*
	cout << "list contents" << endl;
	for (unsigned int k = 0; k < myList.size(); k++){
		cout << myList[k];
	}

	cout << "forward list contents" << endl;
	for (unsigned int k = 0; k < myForwardList.max_size(); k++){
		cout << myForwardList[k];
	}
	*/



	//problem 6
	//explain: their copy constructors only take the same type as themselves as input parameter

	vector<int> anotherVec(myVec);
	deque<int> anotherDeque(myDeque);
	list<int> anotherList(myList);
	forward_list<int> anotherForwardList(myForwardList);


	//vector<int> testVec(myDeque);
	//vector<int> testVec(myList);
	//vector<int> testVec(myForwardList);


	//deque<int> testDeque(myVec);
	//deque<int> testDeque(myList);
	//deque<int> testDeque(myForwardList);


	//list<int> testList(myVec);
	//list<int> testList(myDeque);
	//list<int> testList(myForwardList);


	//forward_list<int> testFl(myVec);
	//forward_list<int> testFl(myDeque);
	//forward_list<int> testFl(myList);







	




	return 0;
}



void passContainer(const vector<int> &vec){
	vector<int>::const_iterator  vIter = vec.begin();
	cout << "vector contents" << endl;
	for (auto pos = vIter; pos != vec.end(); pos++){
		cout << *pos;
	}
	cout << endl;
}


