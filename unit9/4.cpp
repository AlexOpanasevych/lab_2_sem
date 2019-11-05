#include <iostream>
using namespace std;

int main(){
    cout.setf(ios::hex | ios::showbase, ios::basefield);
    cout << 10;
    cout.unsetf(ios::showbase | ios::hex);
    return 0;
}