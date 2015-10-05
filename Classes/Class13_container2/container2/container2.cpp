// container2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
int main(int argc, char* argv[])
{
	set<string> s;
	
	//problem2: auto variable is a pair with iterator in the first position
	//and bool value to indicate if method is successful, so we can use bool
	//to determine if method succeeds
	auto call1 = s.insert("one");
	if (call1.second == false){
		cout << "Inserting 'one' fails" << endl;
	}
	else{
		cout << "Inserting 'one' successfull" << endl;
	}


	auto call2 = s.insert("one");
	if (call2.second == false){
		cout << "Inserting 'one' fails" << endl;
	}
	else{
		cout << "Inserting 'one' successfull" << endl;
	}


	auto call3 = s.insert("two");
	if (call3.second == false){
		cout << "Inserting 'two' fails" << endl;
	}
	else{
		cout << "Inserting 'two' successfull" << endl;
	}


	auto call4 = s.insert("two");
	if (call4.second == false){
		cout << "Inserting 'two' fails" << endl;
	}
	else{
		cout << "Inserting 'two' successfull" << endl;
	}



	//problem 3: multiset insertion is always successful
	cout << "multiset" << endl;
	multiset<string> ms;
	auto call11 = ms.insert("one");
	cout << "Inserting 'one' is successful" << endl;
	auto call12 = ms.insert("one");
	if (call12 == call11){
		cout << "Inserting 'one' fails" << endl;
	}
	else{
		cout << "Inserting 'one' is successful" << endl;
	}

	auto call13 = ms.insert("two");
	if (call13 == call12){
		cout << "Inserting 'two' fails" << endl;
	}
	else{
		cout << "Inserting 'two' is successful" << endl;
	}

	auto call14 = ms.insert("two");
	if (call14 == call13){
		cout << "Inserting 'one' fails" << endl;
	}
	else{
		cout << "Inserting 'one' is successful" << endl;
	}


	//problem 4
	auto range = ms.equal_range("two");
	ostream_iterator<string> printer(cout, " ");
	copy(range.first, range.second, printer); 
	cout << endl;


	//problem 5
	while (range.first != range.second){
		copy(range.first, range.second, printer);
		cout << endl;
		ms.erase(range.first);
		range = ms.equal_range("two");
	}

	//problem 6
	multimap<string, int> map;
	map.insert(pair<string, int>("one", 1));
	map.insert(pair<string, int>("one", 2));
	map.insert(pair<string, int>("two", 3));
	map.insert(pair<string, int>("two", 4));

	for (auto pos = map.equal_range("two"); pos.first != pos.second; ++pos.first){
		cout << "Key: " << pos.first->first << " Value: " << pos.first->second << endl;
	}





	return 0;
}

