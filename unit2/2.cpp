/* ----------------------------------------------------------------<Header>-
 Name: 2.cpp
 Title:  Задача 2 .2
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description:  Напишите программу для преобразования метров в футы и футов в дюймы.
Организуйте ввод числа метров и вывод на экран соответствующего числа футов и дюймов.
Повторяйте эту процедуру до тех пор, пока пользователь не введет 0 в качестве числа метров.

 ------------------------------------------------------------------</Header>-*/

#include <iostream>
using namespace std;

struct metric{
    float meters, const1, const2;
};

int main(){
    struct metric m;
    m.const1 = 3.2808399;
    m.const2 = 39.3700787;
    do{
        cout << "Input meters : ";
        cin >> m.meters;
        cout << "To feets : "<<m.meters*m.const1 << endl;
        cout << "To inches : " <<m.meters*m.const2 << endl;
    }while(m.meters != 0);
    return 0;
}