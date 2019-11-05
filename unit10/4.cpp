#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

ostream & tdm(ostream & stream){
    SYSTEMTIME st, lt;
    GetSystemTime(&st);
    GetLocalTime(&lt);
    return stream << "SYSTEM TIME - " << st.wHour << " : " << st.wMinute << endl 
    << "LOCAL TIME - " << lt.wHour << " : " << lt.wMinute << endl
    << "Date : " << st.wDay << ' ' << st.wMonth << ' ' << st.wYear;
}

int main(){
    cout << tdm;
    return 0;
}