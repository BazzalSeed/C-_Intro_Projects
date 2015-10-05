#include "Detector.h"


class Wrapper{
private:
	Detector *p;

public:
	Wrapper() :p(0){
		std::cout << "inside wrapper constructor" << std::endl;
		p = new Detector();
	}

	Wrapper(const Wrapper &a){
		std::cout << "inside wrapper copy constructor" << std::endl;
		p = new Detector(*(a.p));
	}

	~Wrapper(){
		std::cout << "inside wrapper destructor" << std::endl;
		delete p;
	}
	
	
};