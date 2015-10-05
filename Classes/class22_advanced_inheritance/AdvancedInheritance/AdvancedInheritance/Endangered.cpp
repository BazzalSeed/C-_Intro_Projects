#include "stdafx.h"
#include "Endangered.h"
#include <iostream>

using namespace std;


Endangered::Endangered(){
	cout << "Endangered::Endandered()" << endl;
}


Endangered::~Endangered(){
	cout << "Endangered::~Endandered()" << endl;
}

void Endangered::print(){
	cout << "ENDANDERED" << endl;
}