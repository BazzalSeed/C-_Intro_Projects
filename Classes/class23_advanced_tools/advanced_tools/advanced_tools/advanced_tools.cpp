// advanced_tools.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "animal.h"
#include "endangered.h"
#include "bear.h"
#include "panda.h"
#include "grizzly.h"

#include <string>


using namespace std;

int main(int argc, char* argv[])
{
	grizzly g1;
	grizzly g2;
	panda p1("Zhao Fu");
	panda p2("Dai Li");

	cout << endl;

	cout << "g1 is of type: " << typeid(g1).name() << endl;
	cout << "g2 is of type: " << typeid(g2).name() << endl;
	cout << "p1 is of type: " << typeid(p1).name() << endl;
	cout << "p2 is of type: " << typeid(p2).name() << endl;

	cout << endl;

	cout << "g1 and g2 are" << (typeid(g1) == typeid(g2) ? " " : " not ") << "the same" << endl;
	cout << "g1 and p1 are" << (typeid(g1) == typeid(p1) ? " " : " not ") << "the same" << endl;
	cout << "g1 and p2 are" << (typeid(g1) == typeid(p2) ? " " : " not ") << "the same" << endl;
	cout << "g2 and p1 are" << (typeid(g2) == typeid(p1) ? " " : " not ") << "the same" << endl;
	cout << "g2 and p2 are" << (typeid(g2) == typeid(p2) ? " " : " not ") << "the same" << endl;
	cout << "p1 and p2 are" << (typeid(p1) == typeid(p2) ? " " : " not ") << "the same" << endl;


	cout << endl;

	animal* ap = &p1;
	animal* ag = &g1;

	panda* ap1ptr;
	grizzly* ap2ptr;
	grizzly* ag1ptr;
	panda* ag2ptr;

	cout << endl;

	if (ap1ptr = dynamic_cast<panda*>(ap))
	{
		cout << "ap to panda obj cast to panda ptr was successful" << endl;
	}
	else
	{
		cout << "ap to panda obj cast to panda ptr was NOT successful" << endl;
	}

	ap2ptr = dynamic_cast<grizzly*>(ap);
	ap2ptr->growl();
	grizzly *cao = nullptr;
	cout << cao<< endl;
	cao->growl();
	if (ap2ptr)
	{
		cout << "ap to panda obj cast to grizzly ptr was successful" << endl;
	}
	else
	{
		cout << "ap to panda obj cast to grizzly ptr was NOT successful" << endl;
	}
	if (ag1ptr = dynamic_cast<grizzly*>(ag))
	{
		cout << "ap to grizzly obj cast to grizzly ptr was successful" << endl;
	}
	else
	{
		cout << "ap to grizzly obj cast to grizzly ptr was NOT successful" << endl;
	}
	if (ag2ptr = dynamic_cast<panda*>(ag))
	{
		cout << "ap to grizzly obj cast to panda ptr was successful" << endl;
	}
	else
	{
		cout << "ap to grizzly obj cast to panda ptr was NOT successful" << endl;
	}
	
	cout << endl;

	ap1ptr->cuddle();
	ag1ptr->growl();

	cout << endl;

	auto cuddle_ptr = &panda::cuddle;
	auto growl_ptr = &grizzly::growl;

	(ap1ptr->*cuddle_ptr)();
	(ag1ptr->*growl_ptr)();
	(ag2ptr->*cuddle_ptr)();
	(ap2ptr->*growl_ptr)();
	cout << endl;






	panda * p_new = nullptr;


	


	try
	{
		p_new = new panda("Mai Ling");
	}
	catch (bad_alloc e)
	{
		cerr << e.what() << endl;
	}

	delete p_new;

	cout << endl;

	return 0;
}

