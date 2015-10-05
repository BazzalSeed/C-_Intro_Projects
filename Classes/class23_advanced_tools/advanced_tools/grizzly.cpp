#include "stdafx.h"
#include "grizzly.h"

using namespace std;

grizzly::grizzly()
{
	cout << "grizzly::grizzly()" << endl;
}


grizzly::~grizzly()
{
	cout << "grizzly::~grizzly()" << endl;
}

int grizzly::toes()
{
	return 5;
}

void grizzly::print()
{
	endangered::print();
	cout << "This is a grizzly." << endl;
	

}

void grizzly::growl()
{
	cout << "grizzly::growl()" << endl;
}

void grizzly::react()
{
	growl();
}