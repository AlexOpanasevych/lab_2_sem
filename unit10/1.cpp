#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cout.width(30);
    cout.fill(':');
    cout << left << "I hate C++!";
    return 0;
}