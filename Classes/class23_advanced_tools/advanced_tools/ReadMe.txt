1.
CHRIS OGLE
NANA KWAME OWUSU

2.
animal.cpp
bear.cpp
panda.cpp
grizzly.cpp

animal.h
bear.h
panda.h
grizzly.h

3.

animal::animal()
bear::bear()
endangered::endangered()
grizzly::grizzly()
animal::animal()
bear::bear()
endangered::endangered()
grizzly::grizzly()
animal::animal()
bear::bear()
endangered::endangered()
panda::panda()
animal::animal()
bear::bear()
endangered::endangered()
panda::panda()

g1 is of type: class grizzly
g2 is of type: class grizzly
p1 is of type: class panda
p2 is of type: class panda

g1 and g2 are the same
g1 and p1 are not the same
g1 and p2 are not the same
g2 and p1 are not the same
g2 and p2 are not the same
p1 and p2 are the same

panda::~panda()
endangered::~endangered()
bear::~bear()
animal::~animal()
panda::~panda()
endangered::~endangered()
bear::~bear()
animal::~animal()
grizzly::~grizzly()
endangered::~endangered()
bear::~bear()
animal::~animal()
grizzly::~grizzly()
endangered::~endangered()
bear::~bear()
animal::~animal()

4.

PROGRAM OUTPUT

ap to panda obj cast to panda ptr was successful
ap to panda obj cast to grizzly ptr was NOT successful
ap to grizzly obj cast to grizzly ptr was successful
ap to grizzly obj cast to panda ptr was NOT successful

1) WORKS
2) DOES NOT WORK. RETURNS 0/FALSE/NULL_PTR
3) DOES NOT WORK. RETURNS 0/FALSE/NULL_PTR
4) WORKS

5.
	ap1ptr->cuddle();
	ag1ptr->growl();

	cout << endl;

	auto cuddle_ptr = &panda::cuddle;
	auto growl_ptr = &grizzly::growl;

	(ap1ptr->*cuddle_ptr)();
	(ag1ptr->*growl_ptr)();


6.
001B9C00
animal::animal()
bear::bear()
endangered::endangered()
panda::panda()
panda::~panda()
endangered::~endangered()
bear::~bear()
animal::~animal()
001B9C00