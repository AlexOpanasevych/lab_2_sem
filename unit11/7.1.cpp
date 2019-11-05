#include <iostream>
using namespace std;

class base {
public:
	virtual void func() {
		cout << "Using base version of func()\n";
	}
};

class derived1: public base {
public:
	/*virtual void func() {
		cout << "Using derived1 version of func()\n";
	}*/
};

class derived2: public derived1 {
public:
	virtual void func() {
		cout << "Using derived2 version of func()\n";
	}
};

int main () {
	base *p;
	base obj;
	derived1 objd1;
	derived2 objd2;

	p = &obj;
	p->func();
	p = &objd1;
	p->func();
	p = &objd2;
	p->func();
	return 0;
}

// тому що