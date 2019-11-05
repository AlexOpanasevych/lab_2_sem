/* ----------------------------------------------------------------<Header>-
 Name: 9.cpp
 Title: Задача 5.9
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-03-15
 Revised: ____-__-__
 Description: Используя оператор new, покажите, как динамически разместить
переменную типа double и передать ей начальное значение -123.0987.
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    double *p = new double(-123.0987);
    cout.precision(8);
    cout << *p;
    delete p;
    return 0;
}
