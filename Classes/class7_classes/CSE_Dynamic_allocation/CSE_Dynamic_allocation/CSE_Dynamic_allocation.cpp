// CSE_Dynamic_allocation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Detector.h"
#include <iostream>
#include <memory>
#include <vector>
#include <iterator>

using namespace std;


int myFunction(std::shared_ptr<Detector> p){
	std::shared_ptr<Detector> p1 = std::make_shared<Detector>();
	std::shared_ptr<Detector> p2 = std::make_shared<Detector>();
	std::shared_ptr<Detector> p3 = std::make_shared<Detector>();


	cout << "----------------" << endl;
	vector<shared_ptr<Detector>> vec;
	cout << "----------------" << endl;
	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);


	return 0;
}

int main(int argc, char* argv[])


{
	Detector * test = new Detector();
	/*
	std::shared_ptr<Detector> p1 = std::make_shared<Detector>();
	cout << "original 1:" << p1 << endl;
	std::shared_ptr<Detector> p2 = std::make_shared<Detector>();
	cout << "original 2:" << p2 << endl;
	std::shared_ptr<Detector> p3 = std::make_shared<Detector>();
	cout << "original 3:" << p3 << endl;


	cout << "----------------" << endl;
	vector<shared_ptr<Detector>> vec;
	cout << "----------------" << endl;
	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);
	
	auto iter = vec.begin();
	int i = 1;
	while (iter!=vec.end()){
		cout << "vector element " << i << ": " << *iter << endl;
		i++;
		iter++;
	}
	*/


	return 0;
}


