/* ----------------------------------------------------------------<Header>-
 Name: 1.cpp
 Title:  Задача 5.1.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-03-15
 Revised: ____-__-__
 Description:  Используя следующее объявление класса, создайте массив из 10
элементов и инициализируйте переменную ch значениями от А до J. Покажите, что
массив на самом деле содержит эти значения.
#include <iostream>
using namespace std;
class letters {
 char ch;
public:
 letters(char c) { ch = c; }
 char get_ch() { return ch; }
};
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
using namespace std;
class letters {
 char ch;
public:
 letters(char c) { ch = c; }
 char get_ch() { return ch; }
};

int main(){
    letters alpha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    for(int i = 0; i < 10; i++){
        cout << alpha[i].get_ch() << ' ';
    }
    return 0;
}