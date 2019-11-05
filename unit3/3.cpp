/* ----------------------------------------------------------------<Header>-
 Name: 3.cpp
 Title:  Задача 3.3.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-02-28
 Revised: ____-__-__
 Description:  Используйте объединение (union), чтобы поменять местами старший и
младший байты int (Намек: наверное ваш компьютер использует 64-битное целое).
 ------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

union SwapInt{
    int x;
    SwapInt(int x) {this->x = x;}
    char xVal[(sizeof(int))];
    void swapBits();
};

void SwapInt::swapBits(){
    char tmp = xVal[0];
    xVal[0] = xVal[sizeof(int) - 1];
    xVal[sizeof(int) - 1] = tmp;
    cout << "result: " << x;
}

int main(){
    SwapInt s(5);
    s.swapBits();
    return 0;
}