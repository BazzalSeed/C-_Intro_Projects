// CSE332_Studio3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

enum{
	success,wrong_number_arg,open_error_in,open_error_out
};

int message(int argc,char * argv[]){
	if (argc == 3){
		for (int x = 0; x < argc; x++){
			cout << argv[x] << endl;
		}
	}
	else

	{
		cout << "wrong number of arg" << endl;
		cout << argv[0] << " " << "only takes exactly 2 arguments" << endl;
		return 1;
	}
}
int main(int argc, char* argv[])
{
	// problem 2
	/*int arr[2][3][5];
	for (int i = 0; i < 2; i++){
	for (int j = 0; j < 3; j++){
	for (int k = 0; k < 5; k++){

	cout << i << ";" << j << ";" << k << ";" << endl;
	int product = i*j*k;
	arr[i][j][k] = product;
	cout << "Product: " << product << endl;
	}
	}
	}*/




	vector<string> v;
	string word;
	//Problem 3
	/*
	for (int i = 0; i < argc; i++){
		word = string(argv[i]);
	v.push_back(argv[i]);
}
	
	for (size_t x = 0; x < v.size(); x++){
		cout <<  v[x] +"" << endl;
	}
		
		*/


	//Problem 4
	/* 
	for (size_t x = 0; x < argc; x++){
		word = word + argv[x] + " ";

	}
	cout << word.size() << endl;
	istringstream iss(word);
	string print;
	while (iss >> print){
		cout << print << endl;
	}


*/
	// Problem 5
	/*
	if (argc == 3){
		for (int x = 0; x < argc; x++){
			cout << argv[x] << endl;
		}
	}
	else
	
	{
		cout << "wrong number of arg" << endl;
		cout << argv[0] << " " << "only takes exactly 2 arguments" << endl;
		return wrong_number_arg;
	}
	*/


	// Problem 6
	ifstream infile;
	ofstream outfile;
	if (argc != 3){
		cout << "wrong number of arg" << endl;
		cout << argv[0] << " " << "only takes exactly 2 arguments" << endl;
		return wrong_number_arg;
	}

	infile.open(argv[1]);
	outfile.open(argv[2]);
	if (!infile.is_open()){
		cout << "cannot open input file" << endl;
		if (!outfile.is_open()){
			cout << "cannot open output file" << endl;
		}
		return open_error_in;
	}
	/*
	if (!outfile.is_open()){
		
		cout << "cannot open output file" << endl;
		ofstream outfile("out.txt");
	}
	
	*/
	string word1;
	while (infile >> word1){
		outfile << word1;
	}
	infile.close();
	outfile.close();
	return 0;
}

