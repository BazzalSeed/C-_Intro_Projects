
#include "stdafx.h"
#include "test_class.h"
fml::fml()
:seed(0), seed_sucks(0)
	{}

fml::fml(const fml&another)
: seed(another.seed), seed_sucks(another.seed_sucks) {}
int  fml::x() const {
	return seed;
}

void fml::x(int c){
	seed = c;
}


int fml::y() const{
	return seed_sucks;
}
void fml::y(int c){
	seed_sucks = c;
}