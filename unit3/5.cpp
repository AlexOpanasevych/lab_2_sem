/* ----------------------------------------------------------------<Header>-
 Name: 5.cpp
 Title: Задача 3 .5.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-02-28
 Revised: ____-__-__
 Description:  В Unit 2 вы перегружали функцию abs() так, чтобы она находила абсолютные
значения типа int, long и double. Модифицируйте программу, чтобы эти функции стали
встраиваемыми.
 ------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

inline int myabs(int a){
    if(a < 0) return -1*a;
    return a;
}

inline long myabs(long a){
    if(a < 0) return -1*a;
    return a;
}

inline double myabs(double a){
    if(a < 0) return -1*a;
    return a;
}


int main(){
    int a = -10;
    long b = -100;
    double c = -1.4;
    cout << myabs(a) << ' ' << myabs(b) << ' ' << myabs(c);
    return 0;
}