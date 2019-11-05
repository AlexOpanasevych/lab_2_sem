#include <iostream>

using namespace std;


istream &skipchar(istream &in){
    bool readFlag = true;
    while(true){
        char temp;   
        //count++;
        for (int i = 0; i < 5; i++)
        {
            in >> temp;
            if (readFlag) cout << temp << endl;
        }
        readFlag = (readFlag == true) ? false : true;
        
    }
    return in;
}

int main() {
    cin >> skipchar;
    return 0;
}