
#include <iostream>

class Detector{
private:
	unsigned int a;
	unsigned static int b;
public:
	Detector():a(0){
		b = a;
		b++;
		std::cout << "Inside constructor method" << std::endl;
		//std::cout << "Object address: " << this << std::endl;
		//std::cout << "Initialized variable: " << a << std::endl;

	};
	virtual ~Detector(){
		std::cout << "Inside destructor method" << std::endl;
		//std::cout << "Object address: " << this << std::endl;
		//std::cout << "Initialized variable: " << a << std::endl;
	 
	};
	unsigned int get_a(){ 
	    return a;
	};

};

