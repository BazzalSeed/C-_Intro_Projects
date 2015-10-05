// studio5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
//Question 3
/*  
void SB() { throw 5; }

int main(int argc, char* argv[])
{

	SB();
	return 0;
}

*/



//Question 4 
/*
void SB() { throw 5; }

int main(int argc, char* argv[])
{
	try{
		SB();
	}
	catch (int &i){
		cout << i << endl;
	}
	catch (...){
		
		cout <<" Shadiao "<< endl;
	}
	return 0;
}
*/

//Question 5
/*
void SB() { throw 5; }
void SB_char(){
	char* notstring = "hahaha";

	throw *notstring ; }
void SB_string(){
	throw "it is a string";
}
void sb_long(){
	long  l = 4;
	throw l;
}

int main(int argc, char* argv[])
{
	
	
	try{
		sb_long();
	}
	catch (int &i){
		cout << i << endl;
	}
	catch (...){

		cout << " Shadiao " << endl;
	}
	return 0;
}
*/
//Question 6


//int
void SB() {
	
	throw 5;

}
//int*
void sb_int(){
	int i = 5;
	int * p = &i;
	throw p;
}
//char *
void SB_charstar(){
	char* notstring = "hahaha";

	throw notstring;
}
//char
void SB_char(){
	 char* notstring = "hahaha";

	throw * notstring;
}
//string
void SB_string(){
	throw "it is a string";
}
//long
void sb_long(){
	long  l = 4;
	throw l;
}

int main(int argc, char* argv[])
{

	//int
	try{
		
		SB();
	}
	catch (int &i){
		cout << i << endl;
	}
	catch (...){

		cout << " Shadiao " << endl;
	}
	/////////////////////////////////////////////////////
	// int*

	try{

		sb_int();
	}
	catch (int* &i){
		cout << i << endl;
	}
	catch (...){

		cout << " Shadiao " << endl;
	}
	//////////////////////////////////////////////
	//long
	try{
		//sb_long();
		sb_long();
	}
	catch (long &i){
		cout << i << endl;
	}
	catch (...){

		cout << " Shadiao " << endl;
	}
	/////////////////////////////
	//char*
	try{
		SB_charstar();

	}
	
	catch (char* &i){
		cout << (void*)i << endl;
	}
	catch (...){

		cout << " Shadiao " << endl;
	}
	//////////////////////////////////////

	//char*
	try{
		SB_char();

	}

	catch (char &i){
		cout << i << endl;
	}
	catch (...){

		cout << " Shadiao " << endl;
	}
	return 0;
}