// Object-oriented programming.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myclass.h"
using namespace std;
int main(int argc, char* argv[])
{   //Question 2

	MyClass fml1;
	Derived fml2;
	//Question 3
	/*
	MyClass & x = fml1;
	MyClass & y = fml2;
	Derived & z = fml2;
	cout << "fml1" << endl;
	fml1.voidmethod();
	cout << "<----------------->" << endl;
	cout << "fml2" << endl;
	fml2.voidmethod();
	cout << "<----------------->" << endl;
	cout << "x" << endl;
	x.voidmethod();
	cout << "<----------------->" << endl;
	cout << "y" << endl;
	y.voidmethod();
	cout << "<----------------->" << endl;

	cout << "z" << endl;
	z.voidmethod();
	cout << "<----------------->" << endl;
	*/
	MyClass * x = &fml1;
	MyClass * y = &fml2;
	Derived * z = &fml2;
	cout << "fml1" << endl;
	fml1.voidmethod();
	cout << "<----------------->" << endl;
	cout << "fml2" << endl;
	fml2.voidmethod();
	cout << "<----------------->" << endl;
	cout << "x" << endl;
	(*x).voidmethod();
	cout << "<----------------->" << endl;
	cout << "y" << endl;
	(*y).voidmethod();
	cout << "<----------------->" << endl;

	cout << "z" << endl;
	(*z).voidmethod();
	cout << "<----------------->" << endl;
	return 0;
}

