/* ----------------------------------------------------------------<Header>-
 Name: 4.cpp
 Title:  Задача 5 .4.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-03-15
 Revised: ____-__-__
 Description: Измените пример Example 5.3 (см. Unit 5 "Arrays of objects") так, чтобы
получить доступ к двумерному массиву через указатель. Подсказка: в C++, как и в С,
все массивы хранятся непрерывно, слева направо, от младшего элемента к
старшему.
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
using namespace std;
class samp{
    int a;
    public:
        samp(int a) {this->a = a;}
        int get_a() {return a;}
};

int main(){
    samp obj[4][2] = {1, 2, 3, 4, 5, 6, 7, 8};
    samp (*p2)[2] = obj;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            cout << p2[i][j].get_a() << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}