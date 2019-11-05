/* ----------------------------------------------------------------<Header>-
 Name: 12.cpp
 Title: Задача 2.12.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description: Напишите программу, использующую стиль ввода/вывода C++, для ввода двух
целых с клавиатуры и затем вывода на экран результата возведения первого в степень второго.
(Например, пользователь вводит 2 и 4, тогда результатом будет 24, или 16.)

 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cmath>
using namespace std;

int powTO(int a, int b){
    return pow(a, b);
}

int powBE(int a, int b){
    return pow(b, a);
}

int main(){
    int a, b;
    cout << "Input 2 integers : ";
    cin >> a >> b;
    cout << powTO(a, b) << ' ' << powBE(a, b);
    return 0;
}