#include "Detector.h"

using namespace std;
class Wrapper{
public:
	Detector *p;

public:
	Wrapper() {
		std::cout << "inside wrapper constructor" << std::endl;
		p = new Detector();
	}

	Wrapper(const Wrapper &a){

		
		std::cout << "inside wrapper copy constructor" << std::endl;
		std::cout << "numbers of detector Start" << (*a.p).number << std::endl;
		p = new Detector(*(a.p));
		std::cout << "numbers of detector Start" << (*p).number << std::endl;
		std::cout << "numbers of detector END" << p->number << std::endl;
	}

	Wrapper(Wrapper && a){
		cout << "inside move constructor" << endl;
		p = new Detector(*(a.p));
	}

	~Wrapper(){
		std::cout << "inside wrapper destructor" <<p->number<< std::endl;
		
		delete p;
	}
	
	
	Wrapper & operator= (const Wrapper & a){
	std::cout << "numbers of detector Start" << (*p).number << std::endl;
		
		if (this->p == a.p) { 
			
			std::cout << "numbers of detector END" << p->number << std::endl;
			return *this; }

	Wrapper newW(a);
	std::swap((*this).p, newW.p);
	std::cout << "numbers of detector END" << p->number << std::endl;
	return *this;
	}

	Wrapper & operator= (const Wrapper && a){
		cout << "inside wrapper move assignment consturctor" << endl;
		if (&a != this){
			delete p;
			p = new Detector(*(a.p));
		}
		return *this;

	}

};