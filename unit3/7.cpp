/* ----------------------------------------------------------------<Header>-
 Name: 7.cpp
 Title: Задача 3.7.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-02-28
 Revised: ____-__-__
 Description:  Создайте класс Dice, который содержит закрытую целую переменную.
Создайте функцию гоll(), использующую стандартный генератор случайных чисел rand(),
для получения чисел от 1 до 6. Сделайте 5 бросков четырех игральных костей. Функция
roll() должна вывести эти значения на экран.
 ------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

class Dice{
    public:
        int roll();
    private:
        int a;
};

int Dice::roll(){
    //srand(time(NULL));
    a = (rand() % 6) + 1;
    return a;
}

int main(){
    Dice a;
    for(int i = 0; i < 5; i++) cout << a.roll() << ' ';
    return 0;
}