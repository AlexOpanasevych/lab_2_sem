/* ----------------------------------------------------------------<Header>-
 Name: 8.cpp
 Title: Задача 5.8.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-03-15
 Revised: ____-__-__
 Description: Переделайте данную программу так, чтобы в ней использовался
оператор new:
char *p;
p = (char *)malloc(100);
// ...
strcpy(p, " This is a test.");
 Подсказка: Строка — это просто массив символов.
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char *p;
    p = new char[100];
    strcpy(p, " This is a test.");
    cout << p;
    delete [] p;
    return 0;
}
