/* ----------------------------------------------------------------<Header>-
 Name: 2.cpp
 Title:  Задача 5 .2.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-03-15
 Revised: ____-__-__
 Description: Используя следующее объявление класса, создайте массив из 10
элементов, инициализируйте переменную num значениями от 1 до 10, а
переменную sqr — квадратом num.
#include <iostream >
using namespace std;
class squares {
 int num, sqr;
public:
 squares(int a, int b) { num = a; sqr = b; }
 void show() { cout << num << ' ' << sqr << "\n"; }
};
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
using namespace std;
class squares {
 int num, sqr;
public:
 squares(int a, int b) { num = a; sqr = b; }
 void show() { cout << num << ' ' << sqr << "\n"; }
};

int main(){
    squares n[10] = {squares(1, 1), squares(2, 4), squares(3, 9), squares(4, 16), squares(5, 25), 
    squares(6, 36), squares(7, 49), squares(8, 64), squares(9,81), squares(10, 100)};
    for(int i = 0; i < 10; i++)
    {
        n[i].show();
    }
    return 0;
}