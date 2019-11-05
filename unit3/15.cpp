/* ----------------------------------------------------------------<Header>-
 Name: 15.cpp
 Title:  Задача 3.15
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-02-28
 Revised: ____-__-__
 Description:  Проведите эксперимент: если объект производного класса присваивается
другому объекту того же производного класса, будут ли также копироваться данные,
связанные с базовым классом? Чтобы ответить, воспользуйтесь следующими двумя
классами и напишите программу.
class base {
 int a;
public:
 void load_a(int n) { a = n; }
 int get_a() { return a; }
};
class derived: public base {
 int b;
public:
 void load_b(int n) { b = n; }
 int get_b() { return b; }
};
 ------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

class base {
 int a;
public:
 void load_a(int n) { a = n; }
 int get_a() { return a; }
};
class derived: public base {
 int b;
public:
 void load_b(int n) { b = n; }
 int get_b() { return b; }
};

int main(){
    derived a;
    a.load_a(1);
    a.load_b(2);
    derived b = a;
    cout << b.get_a() << ' ' << b.get_b() << endl; 
    return 0;
}