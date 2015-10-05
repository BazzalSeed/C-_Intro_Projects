// Specialized_libarary_facilities.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "Meishuo.h"
#include <tuple>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <regex>
#include <random>
using namespace std;
int main(int argc, char* argv[])
{
	//Question fking 1
	/*
	typedef tuple <unsigned int, string> student;
	
	student seed, jing, cao, shadiao;
	 seed = make_tuple(1234, "Seed");
	 jing = make_tuple(2321, "Jing");
	 cao = make_tuple (0321, "Cao");
	 shadiao = make_tuple(4321, "SHADIAO");
	cout << get<0>(jing) << endl;
	cout << get<1>(jing) << endl;
	cout << get<0>(seed) << endl;
	cout << get<1>(seed) << endl;
	*/
	// Question 2

	/*
	typedef tuple <unsigned int, string> student;

	student seed, jing, cao, shadiao;
	seed = make_tuple(1234, "Seed");
	jing = make_tuple(2321, "Jing");
	cao = make_tuple(9321, "Cao");
	shadiao = make_tuple(4321, "SHADIAO");
	vector<student> v;
	v.push_back(seed);
	v.push_back(shadiao);
	v.push_back(cao); v.push_back(jing);
	for (student i : v){
		cout <<"id: "<< get<0>(i) <<"name: "<< get<1>(i) << endl;
	}
	cout << endl;
	cout << endl;
	sort(v.begin(), v.end());
	for (student i : v){
		cout << "id: " << get<0>(i) << "name: " << get<1>(i) << endl;
	}
	*/

	//Question 3
	enum years{
		
		
	};
	typedef tuple <unsigned int, string> student;
	/*
	bitset<2> year1 (string ("00"));
	bitset<2> year2(string("01"));
	bitset<2> year3(string("10"));
	bitset<2> year4(string("11"));
	*/
	/*
	student seed, jing, cao, shadiao;
	seed = make_tuple(1234, "A");
	jing = make_tuple(2321, "Jing");
	cao = make_tuple(0321, "Cao");
	shadiao = make_tuple(4321, "SHADIAO");
	
	vector<student> v;
	v.push_back(seed);
	v.push_back(shadiao);
	v.push_back(cao); v.push_back(jing);

	regex pattern("(^[A-M])");
	for (unsigned int i = 0; i<v.size(); i++){
		if (regex_search(get<1>(v[i]), pattern)){
			cout << "matched" << get<0>(v[i])<<" "<< get<1>(v[i])<< endl;
		}
		else{
			cout << "no matches  " << get<0>(v[i]) <<"  " << get<1>(v[i]) << endl;
		}
	}
	*/
	default_random_engine e(time(0));
	student seed, jing, cao, shadiao;
	vector<student> Huluwa;
	Huluwa.push_back(seed);
	Huluwa.push_back(shadiao);
	Huluwa.push_back(cao); Huluwa.push_back(jing);
	for (size_t i = 0; i < 4; i++) {
		Huluwa[i] = make_tuple( e(), "huluwa");
	}
	for (student i : Huluwa){
		cout << "id: " << get<0>(i) << "name: " << get<1>(i) << endl;
	}

	return 0;
}

