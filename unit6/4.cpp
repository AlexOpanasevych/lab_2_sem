#include <iostream>
#include <cstdlib>
using namespace std;
class myclass {
    int *ptr;
public:
    myclass(int i);
    ~myclass() { delete ptr; }
    friend int getval(myclass &obj);
};

myclass::myclass(int i) {
    ptr = new int(i);
    if (!ptr) { exit(1); }
}

int getval(myclass &obj) {
    return *obj.ptr; // get value
}

int main() {
    myclass a(1), b(2);
    cout << getval(a) << " " << getval(b) << "\n";
    cout << getval(a) << " " << getval(b);
    return 0;
}
// program did core dumped because in function  getval was created a copy of an object, and in function we want to return pointer,
// but pointer is cannot returned because it's copy, so we must use reference