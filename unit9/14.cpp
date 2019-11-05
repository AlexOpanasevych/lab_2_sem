#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cout.setf(ios::left);
    cout.precision(6);
    cout.width(20);
    cout.fill('*');
    cout << 1000.5364;
    return 0;
}