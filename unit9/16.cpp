#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cout.setf(ios::boolalpha | ios::uppercase);
    cout << true;
    cout << setfill('X') << setw(80);
    cout << "privet " << 26;
    return 0;
}