#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){
    ofstream out("phones.txt");
    string buffer;
    string NumberTel;
    do{
        getline(cin, buffer);
        getline(cin, NumberTel);
        if(buffer != "" || NumberTel != "") out << buffer << ", " << NumberTel << endl;
    }
    while(buffer != "" || NumberTel != "");
    
    return 0;
}