// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>;
#include <numeric>;

using namespace std;


int main(int argc, char* argv[]){
	int arr[] = { -2, 19, 80, -47, 80, 80, -2 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	int *start = arr;
	int *end = start + arrSize;
	ostream_iterator<int> iter(cout, ", ");
	cout << "print contents of array: " << endl;
	copy(start, end, iter);

	vector<int> vec;
	back_insert_iterator<vector<int>> vecIter(vec);
	//add element to vector
	copy(start, end, vecIter);
	//print element
	cout << "print contents of vector: " << endl;
	copy(vec.begin(), vec.end(), iter);

	sort(start, end);
	cout << "sorted array: " << endl;
	copy(start, end, iter);
	sort(vec.begin(), vec.end());
	cout << "sorted vector: " << endl;
	copy(vec.begin(), vec.end(), iter);

	vector<vector<int>::iterator> index;
	vector<int>::iterator temp;
	vector<int>::iterator it;
	it = adjacent_find(vec.begin(), vec.end());
	temp = adjacent_find(vec.begin(), vec.end());
	while(it != vec.end()){

		cout << "Repeated pair: " << *it << endl;
		index.push_back(it);
		it++;
		it = adjacent_find(it, vec.end());
	}

	int i;


	for (int i = 1; i<index.size(); i++){
		if (*index[i - 1] == *index[i]){
			index.erase(index.begin() + i);
		}
	}




	for (i = 0; i < index.size(); i++){
		vector<int>::iterator curr = index[i];
		int val = *curr;
		while (curr != vec.end()){
			if (*curr == val){
				cout << val << endl;
				curr++;
			}
			else{
				break;
			}
		}
	}


	if (arrSize % 2 != 0){
		cout << "Array median: " << arr[arrSize / 2] << endl;
		cout << "Vector median: " << vec[vec.size() / 2] << endl;
	}
	else{
		cout << "Array median: " << (arr[arrSize / 2] + arr[arrSize / 2 +1])/2 << endl;
		cout << "Vector median: " << (vec[vec.size() / 2] + vec[vec.size()/2+1])/2 << endl;
		
	}

	cout << "Array averge: " << accumulate(arr, arr + arrSize, 0.0)/arrSize << endl;
	cout << "Vector average: " << accumulate(vec.begin(),vec.end(),0.0)/arrSize << endl;

	int k;
	int maxCount = 0;
	int mode = 0;
	for (k = 0; k < arrSize; ++k){
		int counter = count(arr, arr+arrSize, arr[k]);
		if (counter > maxCount){
			maxCount = counter;
			mode = arr[k];
		}
	}

	cout << "Array mode: " << mode << "with " << maxCount << " times" << endl;
	cout << "Vecotr mode: " << mode << "with " << maxCount << " times" << endl;

	return 0;
}

