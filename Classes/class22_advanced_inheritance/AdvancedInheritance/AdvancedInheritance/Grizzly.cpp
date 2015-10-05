#include "stdafx.h"
#include "Grizzly.h"
#include <iostream>
#include <string>

using namespace std;

Grizzly::Grizzly(){
	cout << "Grizzly::Grizlly()" << endl;
}

Grizzly::~Grizzly(){
	cout << "Grizzly:~Grizzly()" << endl;
}


void Grizzly::growl(){
	cout << "Grizzly::growl()" << endl;
}

void Grizzly::print(){
	Endangered::print();
	cout << "Animal Type: Grizzly" << endl;
}

int Grizzly::toes(){
	cout << "Grizzly::toes()" << endl;
	return  5;
}

void Grizzly::react(){
	growl();
}