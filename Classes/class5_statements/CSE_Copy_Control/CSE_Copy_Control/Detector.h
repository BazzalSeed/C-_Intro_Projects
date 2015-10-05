#include <iostream>

class Detector{
private:
	unsigned int a;
	unsigned static int b;
public:
	Detector() :a(0){
		b = a;
		b++;
		std::cout << "--- Inside Detector constructor method" << std::endl;
		std::cout << "Object address: " << this << std::endl;
		std::cout << "Initialized variable: " << a << std::endl;

	};
	Detector(const Detector& d) {
		a = d.a;
		b = d.b;
		std::cout << "--- Inside Detector Copy constructor" << std::endl;
	};
	virtual ~Detector(){
		std::cout << "--- Inside Detector destructor method" << std::endl;
		std::cout << "Object address: " << this << std::endl;
		std::cout << "Initialized variable: " << a << std::endl;

	};
	
	unsigned int get_a(){
		return a;
	};

};

