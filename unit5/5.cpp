/* ----------------------------------------------------------------<Header>-
 Name: 5.cpp
 Title:  Задача 5 .5
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-03-15
 Revised: ____-__-__
 Description: . Напишите программу, в которой оператор new используется для
динамического размещения переменных типа float, long и char. Задайте этим
динамическим переменным значения и выведите эти значения на экран. В
завершение с помощью оператора delete освободите всю динамически выделенную
область памяти.
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
using namespace std;

int main(){
    float *b = new float(2.5);
    long *a = new long(10000);
    char *c = new char('A');
    cout << *b << ' ' << *a << ' ' << *c;
    delete a;
    delete b;
    delete c;
    return 0;
}