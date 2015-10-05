#include <iterator>


template<typename Iterator>
size_t counter(Iterator iter1, Iterator iter2){
	cout << "----------using ++ operator--------" << endl;
	size_t res = 0;
	while (iter1 != iter2){
		res++;
		iter1++;
	}
	cout << "-----------------------------" << endl;
	return res;
}



template<typename Iterator>
size_t counter(Iterator iter1, Iterator *iter2){
	cout << "---------using random access--------------" << endl;
	cout << "--------------------------------------------" << endl;
	return *iter2 - *iter1;
}

template<typename Iterator>
size_t counting(Iterator *iter1, Iterator *iter2){
	int *ptr1 = iter1;
	int *ptr2 = iter2;
	size_t res = 0;

	while (ptr1 != ptr2){
		cout << (*ptr1) << " ";
		ptr1++;
		res++;
	}
	cout << endl;
	return res;
}


template<typename Iterator>
size_t counting1(Iterator *iter1, Iterator *iter2){
	char *ptr1 = iter1;
	char *ptr2 = iter2;
	size_t res = 0;

	while (ptr1 != ptr2){
		cout << (*ptr1);
		ptr1++;
		res++;
	}
	cout << endl;
	return res;
}