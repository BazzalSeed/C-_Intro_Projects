// advanced_inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "animal.h"
#include "bear.h"
#include "endangered.h"
#include "panda.h"
#include "grizzly.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	panda p("yao_ming");
	grizzly g;
	cout << endl;
	int pt = p.toes();
	p.print();
	//p.growl();
	p.cuddle();

	int gt = g.toes();
	g.print();
	g.growl();
	//g.cuddle();

	cout << endl;

	p.react();
	g.react();

	cout << endl;

	animal* ap = &p;
	animal* ag = &g;

	ap->react();
	ag->react();

	ap->cuddle();
	ap->growl();

	ag->cuddle();
	ag->growl();


	return 0;
}

