#include <iostream>

#include <iomanip>
using namespace std;

ostream & myset(ostream & stream){
    stream.precision(5);
    return stream;
}

ostream & mysetup(ostream & str){
    //str.precision(5);
    return str << setprecision(5);
}

int main(){
    cout << myset << (float)10/3 << endl;
    cout << mysetup << (float)10/3;
    return 0;
}