#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;

void center(const char *s){
    int len = strlen(s);
    cout << setw(40 + (len/2));
    cout << s << endl;
}

int main(){
    for(int i = 2; i <= 100; i++){
        cout.width(10);
        cout.precision(5);
        cout << right << i << ' ' << log(i) << ' ' << log10(i) << endl;
    }
    const char * s = "MY LOVER";
    center(s);
    return 0;
}