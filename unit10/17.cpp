#include <iostream>

using namespace std;

ostream& table(ostream &out){
    out << "\t\t\t";
    out.width(20);
    return out;
}

int main() {
    cout << table << "Hello world!" << endl;

    return 0;
}