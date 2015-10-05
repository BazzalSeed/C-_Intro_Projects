
#include<iostream>
using namespace std;
template<typename T>

struct myS
{
	myS(const T& c){
		jing = c;
	}
	T  jing;
	
	bool operator == ( const myS<T> & s) const {
		return jing == s.jing;
	}
	
	bool operator < (const myS<T> & s) const {
		return jing < s.jing;
	}


};

template<typename T>
ostream & operator<< (ostream & os, const  myS<T> & s){
	os << s.jing << endl;
	return os;
}

