/* ----------------------------------------------------------------<Header>-
 Name: 8.cpp
 Title: Задача 2.8.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description: Создайте функцию myroot(), которая возвращает квадратный корень своего
аргумента. Перегрузите myroot() тремя способами (см. Unit 2 "Introducing Function Overloading"):
чтобы получить квадратный корень целого, длинного целого и числа с плавающей точкой
двойной точности. (Для непосредственного подсчета квадратного корня вы можете
использовать стандартную библиотечную функцию sqrt().

 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <math.h>
using namespace std;

double myroot(int a);
double myroot(long int a);
double myroot(double a);

int main(){
    int a; long int b; double c;
    cout << "Input 3 floats : ";
    cin >> a >> b >> c;
    cout << myroot(a) << ' ' << myroot(b) << ' ' << myroot(c);
}

double myroot(int a){
    a = (double)a;
    return sqrt(a);
}

double myroot(long int a){
    a = (double)a;
    return sqrt(a);
}

double myroot(double a){
    return sqrt(a);
}