#include <iostream>
#include <ostream>
#include <fstream>
#include <istream>
using namespace std;

class fml{
public:
	int seed;
	int seed_sucks;

	fml();
	fml(const fml & fanother);

	friend ostream& operator << (ostream & out, const fml & wut);
	friend istream &operator >> (istream & is, fml & wut);
	int  x() const;
	int y() const;
	void x(int c);
	void y(int c);

};