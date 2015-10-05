

#include <iostream>

using namespace std;

class MyClass{
	
public :
	int m;
	friend ostream& operator<<(ostream &os, const MyClass & c);
	MyClass(int n = 0);
	bool operator< (const MyClass &c);
	bool operator== (const MyClass &c);
	MyClass operator+ (const MyClass &c);
	MyClass& operator= (const MyClass &c);
};




