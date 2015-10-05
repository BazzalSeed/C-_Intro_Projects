1.
NANA KWAME OWUSU
CHRIS OGLE

2. None of them can be instatiated because they all contain pure virtual methods.
the endangered class also defines a pure virtual method, which is illegal.

3. 
animal::animal()
bear::bear()
endangered::endangered()
panda::panda()
animal::animal()
bear::bear()
endangered::endangered()
grizzly::grizzly()
grizzly::~grizzly()
endangered::~endangered()
bear::~bear()
animal::~animal()
panda::~panda()
endangered::~endangered()
bear::~bear()
animal::~animal()

4.
For the panda object, all calls except for the growl() method could be made
because growl() is not declared and defined in the panda class or any of its 
parent classes.

For the grizzly object, all calls except for the cuddle() method could be made
because cuddle() is not declared and defined in the grizzly class or any of its 
parent classes.

animal::animal()
bear::bear()
endangered::endangered()
panda::panda()
animal::animal()
bear::bear()
endangered::endangered()
grizzly::grizzly()

ENDANGERED!
This is a panda called:
yao_ming
panda::cuddle()
ENDANGERED!
This is a grizzly.
grizzly::growl()

grizzly::~grizzly()
endangered::~endangered()
bear::~bear()
animal::~animal()
panda::~panda()
endangered::~endangered()
bear::~bear()
animal::~animal()

5.

panda::cuddle()
grizzly::growl()

6.
same: animal pointers to the panda and grizzly objects could not call their 
undeclared non-virtual methods, growl()[undeclared in panda] and cuddle()[undeclared
in grizzly] respectively.

different: 
animal pointers to the grizzly and panda objects could also not call their 
own non-virtual methods, growl() and cuddle() respectively. base class pointer/
references can only call virtual derived class methods.

