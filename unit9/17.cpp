#include <iostream>
#include <cmath>
using namespace std;

class pwr {
    int base;
    int exponent;
    double result; // base to the exponent power
    public:
    pwr(int b, int e);
    void show(){
        cout << result;
    }
};
pwr::pwr(int b, int e) {
    base = b;
    exponent = e;
    result = 1;
    for ( ; e; e--) result = result * base;
}

int main(){
    pwr p(100, 2);
    p.show();
    return 0;
}