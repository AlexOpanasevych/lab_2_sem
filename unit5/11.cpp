/* ----------------------------------------------------------------<Header>-
 Name: 11.cpp
 Title: Задача 5.11
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-03-15
 Revised: ____-__-__
 Description: Напишите функцию neg(), которая меняет знак своего целого параметра
на противоположный. Напишите функцию двумя способами: первый — используя
параметр-указатель и второй — параметр-ссылку. Составьте короткую программу
для демонстрации обеих функций.
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
using namespace std;

void neg(int * n){
    *n *= -1;
}

void neg(int &n){
    n *= -1;
}

int main(){
    int n = -10;
    cout << "Before: " << n << endl;
    neg(&n);
    cout << "Using pointer: " << n << endl;
    neg(n);
    cout << "Using reference: " << n << endl;
    return 0;
}
