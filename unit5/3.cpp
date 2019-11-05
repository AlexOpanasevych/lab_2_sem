/* ----------------------------------------------------------------<Header>-
 Name: .cpp
 Title:  Задача 5 .2.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-03-15
 Revised: ____-__-__
 Description:  Используя следующее объявление класса, создайте массив из 10
элементов, инициализируйте переменную num значениями от 1 до 10, а
переменную sqr — квадратом num.
#include <iostream >
using namespace std;
class squares {
 int num, sqr;
public:
 squares(int a, int b) { num = a; sqr = b; }
 void show() { cout << num << ' ' << sqr << "\n"; }
};
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
using namespace std;

class samp{
    int a, b;
    public:
        samp(int a, int b) {this->a = a; this->b = b;}
        int get_a() {return a;}
        int get_b() {return b;}
};

int main(){
    samp obj[4] = {samp(1, 2), samp(3,4), samp(5,6), samp(7,8)};
    samp *p = &obj[3];
    for (int i = 0; i < 4; i++){
        cout << p->get_a() << ' ';
        cout << p->get_b() << '\n';
        p--;
    }
    cout << '\n';
    return 0;
}