/* ----------------------------------------------------------------<Header>-
 Name: 10.cpp
 Title:  Задача 2.10.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description: Создайте свою функцию min(), которая возвращает наименьший из двух численных
аргументов, используемых при ее вызове. Перегрузите функцию min() так, чтобы она
воспринимала в качестве аргументов символы, целые и действительные двойной точности (см.
Unit 2 "Introducing Function Overloading").

 ------------------------------------------------------------------</Header>-*/

#include <iostream>
using namespace std;

int min(int a, int b){
    return a < b ? a : b;
}
float min(float a, float b){
    return a < b ? a : b;
}
char min(char a, char b){
    return (int)a < (int)b ? a : b;
}

int main(){
    int a = 1, b = 2;
    float c = 2.44, d = 2.45;
    char e = 65, f = 66;
    cout << min(a, b) << ' ' << min(c, d) << ' ' << (char)min(e, f);
    return 0;
}