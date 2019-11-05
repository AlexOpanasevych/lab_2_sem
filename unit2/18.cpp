/* ----------------------------------------------------------------<Header>-
 Name: 18.cpp
 Title: создать класс mybox
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description: 
 Создайте класс mybox, конструктору которого передаются три значения типа double,
представляющие собой длины сторон параллелепипеда. Класс mybox должен подсчитывать его
объем и хранить результат также в виде значения типа double. Включите в класс функцию-член
volume(), которая будет выводить на экран объем любого объекта типа mybox.
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
using namespace std;

class mybox{
    double side1;
    double side2;
    double side3;
    double vlm;
    public:
        mybox(double side1, double side2, double side3);
        void volume();
};

mybox::mybox(double side1, double side2, double side3){
    vlm = side1*side2*side3;
}

void mybox::volume(){
    cout << "Volume is " << vlm; 
}

int main(void){
    mybox box(1, 2, 3);
    box.volume();
    return 0;
}