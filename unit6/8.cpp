#include <iostream>
using namespace std;

int dif(int a, int b) {
    return a-b;
}
float dif(float a, float b) {
    return a-b;
}

int main() {
    int (*f1)(int, int);
    float (*f2)(float, float);
    f1 = dif;
    cout << f1(1, 2) << endl;
    f2 = dif;
    cout << f2(3.5, 4.5) << endl;
    return 0;
}