// AdvancedInheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Panda.h"
#include "Grizzly.h"
#include <iostream>

using namespace std;


int main(int argc, char* argv[]){
	Panda p("jing");
	Grizzly g = Grizzly();


	Endangered* huluwa = dynamic_cast<Endangered*>(&p);
	cout << "----------------" << endl;
	cout << "----------------" << endl;
	huluwa->print();
	cout << "----------------" << endl;
	cout << "----------------" << endl;
	p.react();
	g.react();


	return 0;
}

