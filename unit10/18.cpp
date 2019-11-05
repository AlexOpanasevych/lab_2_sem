#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;


istream & findalpha(istream & stream){
    char temp;
    while (!stream.eof())
    {
        stream.get(temp);
        if (!isalpha(temp)) continue;
        else {
            cout << temp;
            return stream;
        }
    }
    return stream;
}

int main() {
    cin >> findalpha;
    return 0;
}