#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

void myclreol(int cursor = 0){
    if (cursor == 0) {
        cout << "\r";
        for(int i = 0; i < 80; i++){
            cout << ' ';
        }
    }
    for(int i = 0; i < cursor; i++){
        cout << '\b'; 
    }
    for(int i = 0; i < cursor; i++)
    {
        cout << ' ';
    }
}

int main() {
    string line;
    cout << "enter string, sir: ";
    getline(cin, line);
    cout << line << flush;
    myclreol(5);
    Sleep(3000);
    cout << endl;
    cout << line << flush;
    Sleep(3000);
    myclreol();
    return 0;
}