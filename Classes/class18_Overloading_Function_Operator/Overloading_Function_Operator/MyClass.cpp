#include "stdafx.h"
#include "MyClass.h"



MyClass::MyClass(int n){

	m = n;
}

ostream & operator << (ostream &os, const MyClass & c)
{
	os << c.m;
	return os;
}

bool MyClass::operator<(const MyClass &c){
	return this->m < c.m;
}


bool MyClass::operator==(const MyClass &c){
	return this->m == c.m;
}


MyClass MyClass::operator+ (const MyClass &c) {
	return MyClass(this->m + c.m);
}


MyClass& MyClass::operator=(const MyClass &c){
	if ((*this) == c){
		return (*this);
	}

	this->m = c.m;
	return (*this);
}