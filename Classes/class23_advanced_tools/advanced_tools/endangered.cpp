#include "stdafx.h"
#include "endangered.h"

using namespace std;

endangered::endangered()
{
	cout << "endangered::endangered()" << endl;
}


endangered::~endangered()
{
	cout << "endangered::~endangered()" << endl;
}

void endangered::print()
{
	cout << "ENDANGERED!" << endl;
}