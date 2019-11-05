/* ----------------------------------------------------------------<Header>-
 Name: 13.cpp
 Title: Задача 5.13.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-03-15
 Revised: ____-__-__
 Description: Попытайтесь найти полезное применение для независимой ссылки.
Напишите демонстрационную программу.
 ------------------------------------------------------------------</Header>-*/


#include <iostream>
#include <cstring>
using namespace std;

class number{
    private:
        int x;
    public:
        number(int x) {this->x = x;}
        int get(){ return x;}
        int &ref = x;
};

// I think independent reference is great equivalent to get() function,
// we don't need to create function, we just create public reference and use
// them, so private variable can be used in class members functions
int main(){
    number n(5);
    n.ref = 100;
    cout << n.ref << ' ' << n.get();
    return 0;
}
