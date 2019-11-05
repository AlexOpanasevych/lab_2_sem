#include <iostream>
using namespace std;

int main(){
    cout.setf(ios::scientific | ios::uppercase | ios::showpoint);
    cout << 5.25 << ' ' << 10.90 << ' ' << 15.12;
    return 0;
}