// Overloading_Function_Operator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyClass.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]){
	const MyClass m1(1);
	const MyClass m2(2);
	const MyClass m3(3);
	const MyClass m4(4);
	const MyClass m5(5);
	const MyClass m6(6);
	
	/*
	cout << (m1 < m2) << endl;
	cout << (m1 == m2) << endl;

	m1 = m2;

	cout << (m1 < m2) << endl;
	cout << (m1 == m2) << endl;

	MyClass m3 = m1 + m2;
	cout << (m1 < m2) << endl;
	cout << (m1 == m3) << endl;

	m1 = m2 = m3;
	cout << (m1 < m2) << endl;
	cout << (m1 == m3) << endl;
	*/


	vector<const MyClass> vec;
	vec.push_back(m2);
	vec.push_back(m3);
	vec.push_back(m5);
	vec.push_back(m1);
	vec.push_back(m6);
	vec.push_back(m4);

	sort(vec.begin(), vec.end());
	for (size_t i = 0; i < 6; ++i){
		cout << vec[i] << endl;
	}



	

}

