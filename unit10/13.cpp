#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    string namefile;
    cout << "Input name of file: ";
    cin >> namefile;
    ifstream in(namefile);
    string buffer;
    while (!in.eof())
    {
        getline(in, buffer);
        cout << buffer << endl;
    }
    return 0;
}