#include "stdafx.h"
#include "factorial.h"
using namespace std;

//question 3
int factorial_loop(int f){
	if (f <= 0){
		return -1;
	}
	int product = 1;
	for (int i=1; i < f+1; ++i){
		product = product * i;

	}
	return product;
}
int factorial_recursion(int f){

	if (f == 1){
		return 1;
	}
	else{
		return f*factorial_recursion(f-1);
	}
}
//question 4
void factorial_loop_ref(int f,int&result){
	if (f <= 0){
		cout<< "you suck"<<endl;
		exit;
	}
	int product = 1;
	for (int i = 1; i < f + 1; ++i){
		product = product * i;
		result = product;
	}
	
}
//question 5
void factorial_loop_pointer(int f, int * result){
	if (f <= 0){
		cout << "you suck" << endl;
		exit;
	}
	int product = 1;
	for (int i = 1; i < f + 1; ++i){
		product = product * i;
		*result = product;
	}
}
int power(int i, int j){
	int result = 1;
	for (int n = 0; n < j; ++n){
		result = result *i;
	}
	return result;
}