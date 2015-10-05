#include "stdafx.h"
#include "Panda.h"
#include <iostream>
#include <string>

using namespace std;


Panda::Panda(string s){
	name = s;
	cout << "Panda::Panda()" << endl;
}


Panda::~Panda(){
	cout << "Panda::~Panda()" << endl;
}

void Panda::cuddle(){
	cout << "Panda::cuddle()" << endl;
}


void Panda::print(){
	Endangered::print();
	cout << "Animal Type: Panda" << endl;
	cout << "Animal Name: " << name << endl;
}

int Panda::toes(){
	cout << "Panda::toes()" << endl;
	return 6;
}


void Panda::react(){
	cuddle();
}