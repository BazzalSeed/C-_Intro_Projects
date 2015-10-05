// Studio7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include "test_class.h"
using namespace std;
int main(int argc, char* argv[])
{     
	fml test = fml();
	const fml  test_const = fml();

	  cout << test_const.x()<< endl;
	  cout << test.x() << endl;
	  test.x(4);
	  cout << test.x() << endl;
	  test.y(2);
	  fml m ; // default construction
	  cout << "m.x = " << m.x() << " and m.y = " << m.y() << endl;
	  m.x(7); // chained use of mutator functions
	  m.y(3);
	  cout << "m.x = " << m.x() << "and m.y = " << m.y() << endl;
	  fml n(m); // copy construction
	  cout << "n.x = " << n.x() << " and n.y = " << n.y() << endl;
	
	  
	  return 0;
}

