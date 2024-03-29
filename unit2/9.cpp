/* ----------------------------------------------------------------<Header>-
 Name: 9.cpp
 Title: Задача 2.9.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description: Стандартная библиотека C++ содержит три функции:
double atof (const char *s);
int atoi (const char *s);
long atol(const char *s);
Эти функции возвращают численное значение, содержащееся в строке, на которую указывает s.
Заметьте, что atof() возвращает double, atoi возвращает int и atol возвращает long. Почему нельзя
перегрузить эти функции? Продемонстрируйте пример кода.(ответ внизу)

 ------------------------------------------------------------------</Header>-*/

#include <iostream>
using namespace std;

int atof(const char *s);

int main(){
    char * s = "123.123";
    double a = atof(s);
    return 0;
}

// (программа не компилируется!!!)эти функции нельзя перегружать, 
// поскольку они принимают один и тот же аргумент и возвращают определенное значение. 
// Как например, если мы перегрузим функцию atof, компилятору узнать, какое число задано в строке?