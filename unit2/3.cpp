/* ----------------------------------------------------------------<Header>-
 Name: 3.cpp
 Title:  Задача 2.3.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description: Ниже приведена программа на языке С. Перепишите ее в соответствии со стилем
ввода/вывода C++.

 ------------------------------------------------------------------</Header>-*/

#include <iostream>
using namespace std;
int main(void) {
    int a, b, d, min;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    min = a>b?b:a;
    for (d=2; d<min; d++){
        if (((a%d) == 0) && ((b%d) == 0)) break ;
        if (d==min) {
            cout << "No common denominators" << "\n";
            return 0;
        }
    }
    cout << "The lowest common denominator is "<< d << endl;
    return 0;
}
