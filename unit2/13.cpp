/* ----------------------------------------------------------------<Header>-
 Name: 13.cpp
 Title: Задача 2.13.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description: Создайте функцию rev_str() для изменения порядка следования символов строки на
обратный. Перегрузите rev_str() так, чтобы она могла вызываться с одним или двумя
символьными строками. Если функция вызывается с одной строкой, то операция должна
осуществляться с ней. Если она вызывается с двумя строками, то результирующая строка должна
оказаться во втором аргументе (см. Unit 2 "Overloaded functions that differ in the number of their
arguments"). Например:
char s1 [80], s2 [80];
strcpy (s1, "hello");
rev_str(s1, s2); // reversed string goes in s2, s1 untouched
rev_str(s1); // reversed string is returned in s1

 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
using namespace std;

void rev_str(char * src){
    char * temp = new char[80];
    for(size_t i = 0, n = strlen(src); i < n; i++){
        temp[i] = src[n - i - 1];
    }
    memcpy(src, temp, strlen(src));
    delete[] temp;
}

void rev_str(char *src, char *dest){
    for(size_t i = 0, n = strlen(src); i < n; i++){
        dest[i] = src[n - i - 1];
    }
}

int main(){
    char * src = new char[80];
    char * dest = new char[80];
    cout << "Input a string: ";
    cin >> src;
    rev_str(src, dest);
    rev_str(src);
    cout << "In function with one arg: " << src << endl;
    cout << "In second function with two args: " << dest << endl;
    delete[] src;
    delete[] dest;
    return 0;
}