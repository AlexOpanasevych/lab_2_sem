#include <iostream>
#include <typeinfo>
#include <cstring>
using namespace std;
class A {
 virtual void f() {}
};
class B: public A {};

class C : public A {};

int main() {
 A *p, obja;
 B objb;
 C objc;
 int i;
 cout << "Enter 0 for A objects, ";
 cout << "1 for B objects or ";
 cout << "2 for C objects.\n";
 cin >> i;
 getchar();
 if (i==1)
 p = &objb;
 else if (i==2)
 p = &objc;
 else
 p = &obja;
 if (typeid(*p) == typeid(obja))
 {
	cout << "You chosed A" << typeid(p).name() << endl;
 }
 else if(typeid(*p) == typeid(objb))
	cout << "You chosed B" << endl;
 else cout << "You chosed C" << endl;
 return 0;
}