#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cout.setf(ios::right);
    for(int i = 2; i <= 100; i++){
        cout.width(10);
        cout.precision(5);
        cout << i << ' ' << log(i) << ' ' << log10(i) << endl;
    }
    return 0;
}