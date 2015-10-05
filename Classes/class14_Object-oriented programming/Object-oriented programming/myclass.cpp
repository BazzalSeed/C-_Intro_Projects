#include "stdafx.h"
#include "myclass.h"
using namespace std;
MyClass::MyClass()
{
	cout << "using Myclass constructor" << endl;
}

MyClass::~MyClass()
{
	cout << "using Myclass destructor" << endl;
}
void MyClass::voidmethod(){
	cout << "I'm in base void method" << endl;
}


Derived::Derived(){

	cout << "using derived constructor" << endl;
}
Derived::~Derived(){
	cout << "using derived destructor" << endl;
}

void Derived::voidmethod(){
	cout << "using derived void method" << endl;
}