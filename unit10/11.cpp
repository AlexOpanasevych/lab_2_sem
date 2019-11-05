#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class account {
    int custom;
    string name;
    double balance;
public:
    account(int c, const string &n, double b) {
        custom = c;
        name.assign(n);
        balance = b;
    }
    friend ostream &operator <<(ostream &out, account &obj);
};

ostream &operator <<(ostream &out, account &obj){
    out << "Id:\t\t" << obj.custom << endl
        << "Name:\t\t" << obj.name << endl
        << "Balance:\t" << obj.balance << endl;
    return out;
}

int main() {
    const string filename = "text.txt";
    ofstream fileOut(filename);
    if(!fileOut.good() && !fileOut.eof()){
        cerr << "Cannot create output file. Terminating.." << endl;
        exit(1);
    }
    account acc(0, "James", 30);
    fileOut << acc;
    cout << acc;

    return 0;
}