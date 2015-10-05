#include "stdafx.h"
#include "Animal.h"

#include <iostream>

using namespace std;


Animal::Animal(){
	cout << "Animal::Animal()" << endl;
}

Animal::~Animal(){
	cout << "Animal::~Animal()" << endl;

}



void Animal::print(){
	cout << "ANIMAL" << endl;
}