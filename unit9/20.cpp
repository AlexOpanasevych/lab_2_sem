#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

class watch{
    SYSTEMTIME st, lt;
    public:
        void get_time(){
            GetSystemTime(&st);
            GetLocalTime(&lt);
            cout << "SYSTEM TIME - " << st.wHour << " : " << st.wMinute << endl;
            cout << "LOCAL TIME - " << lt.wHour << " : " << lt.wMinute << endl;
        }
};

int main(){
    watch wtch;
    wtch.get_time();
    return 0;
}