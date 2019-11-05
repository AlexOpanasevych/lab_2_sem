#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(){
    cout << dec << 100 << endl;
    cout << hex << showbase << 100 << endl;
    cout << oct << showbase << 100 << endl;
    cout << setw(20);
    cout << setprecision(6);
    cout << setfill('*');
    left(cout);
    cout << 1000.5364;
    return 0;
}