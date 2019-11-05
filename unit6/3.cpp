#include <iostream>
#include <cstring>

using namespace std;

class myclass {
public:
 myclass();
 myclass(const myclass &obj);
 myclass f();
 myclass g(myclass obj);
};
// Normal constructor
myclass::myclass() {
 cout << "Constructing normally\n";
}
// Copy constructor
myclass::myclass(const myclass &obj) {
 cout << "Constructing copy\n";
}
// Return an object.
myclass myclass::f() {
 myclass temp;
 return temp;
}
myclass myclass::g(myclass obj) {
 myclass temp = obj;
 return temp;
}
int main() {
 myclass obj;
 obj = obj.f();
 obj = obj.g(obj);
 return 0;
}