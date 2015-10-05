// IO_Lib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "test_class.h"

int main(int argc, char* argv[])
{
	/*
	fml haha;
	cout << haha << endl;
	int a;
	int i = 0;
	while ( a=2){
		cout << "Give me a fking number dude" << endl;
		cin >> haha;
		i++;
		cout << haha << endl;
	}
	*/
	
	fml haha;
	ifstream file(argv[1]);
	if (!file.is_open()){
		cout << "Sha diao" << endl;
		return 1;
	}
	while (file.good()){
		file >> haha;
	}
	cout << haha << endl;

	ofstream out("lol.txt");
	out << haha << endl;
	




	return 0;

}

