#include "stdafx.h"
#include "panda.h"
#include <string>

using namespace std;

panda::panda(string name)
{
	nom = name;
	cout << "panda::panda()" << endl;
}


panda::~panda()
{
	cout << "panda::~panda()" << endl;
}

void panda::print()
{
	endangered::print();
	cout << "This is a panda called: " << endl;
	cout << nom << endl;
	
}

int panda::toes()
{
	return 6;
}

void panda::cuddle()
{
	cout << "panda::cuddle()" << endl;
}

void panda::react()
{
	cuddle();
}