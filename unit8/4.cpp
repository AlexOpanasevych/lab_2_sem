#include <iostream>
using namespace std;
class mybase {
 int a, b;
public:
int c;
 void setab(int i, int j) { a = i; b = j; }
 void getab(int &i, int &j) { i = a; j = b; }
};
class derived1 : public mybase {
// ...
};
class derived2 : private mybase {
// ...
};
int main() {
 derived1 obj1;
 derived2 obj2;
 int i, j;
 // ...
}

// cases a), c) are right
// because obj1 has public inheritance
// and obj2 has private inheritance