#include <iostream>
using namespace std;

void order(int &x, int &y){
    if(x > y){
        int temp = x;
        x = y;
        y = temp;
    }
}

int main() {
    int a, b;
    a = 5, b = 4;
    cout << a << ' ' << b << endl;
    order(a, b);
    cout << a << ' ' << b << endl;
    order(a, b);
    cout << a << ' ' << b << endl;
    return 0;
}