#include <iostream>
#include <string>



class MyClass
{
public:
	MyClass();
	~MyClass();
	 void voidmethod();
private:

};

class Derived : public MyClass{
public:
	void voidmethod();
	Derived();
	~Derived();
};