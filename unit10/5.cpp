#include <iostream>
using namespace std;
ostream & sethex(ostream & stream){
    //stream.setf(ios::hex | ios::showbase | ios::uppercase);
    return stream << hex << showbase << uppercase;
}

ostream & reset(ostream & stream){
    stream.unsetf(ios::showbase | ios::hex | ios::uppercase);
    return stream;
}

int main(){
    cout << sethex << 100 << " ";
    cout << reset << 100;
    return 0;
}