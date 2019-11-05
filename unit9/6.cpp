#include <iostream>
#include <cstring>
using namespace std;

void center(const char *s){
    int len = strlen(s);
    cout.width(40 + (len/2));
    cout << s << endl;
}

int main(){
    const char * s = "MY LOVER";
    center(s);
    return 0;
}