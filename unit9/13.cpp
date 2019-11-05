#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cout.setf(ios::dec);
    cout << 100 << endl;
    cout.unsetf(ios::dec);
    cout.setf(ios::hex | ios::showbase);
    cout << 100 << endl;
    cout.unsetf(ios::hex);
    cout.setf(ios::oct | ios::showbase);
    cout << 100 << endl;
    return 0;
}