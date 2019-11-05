/* ----------------------------------------------------------------<Header>-
 Name:  2.cpp
 Title: Задача 3 .2.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-02-28
 Revised: ____-__-__
 Description:   Дан следующий базовый класс:
class Area {
public:
 double height;
 double width;
}
Создайте два производных класса Rectangle и Isosceles, которые наследуют базовый класс
Aгеа. Каждый класс должен включать в себя функцию агеа(), которая возвращает площадь
соответственно прямоугольника (rectangle) и равнобедренного треугольника (isosceles).
Для инициализации переменных height и width (высота и длина основания,
соответственно) используйте конструктор с параметрами. Добавьте производный класс,
который наследует класс Aгеа, назовите этот класс Cylinder и пусть он вычисляет площадь
поверхности цилиндра. Эта площадь задается так: 2*pi*R*R + pi*D*height.
 ------------------------------------------------------------------</Header>-*/
#include <iostream>
#include <cmath>

using namespace std;

class Area {
    public:
        double height;
        double width;
        Area(double height, double width);
        double getHeight();
        double getWidth();
};

double Area::getHeight(){
    return height;
}

double Area::getWidth(){
    return width;
}

Area::Area(double height, double width){
    this->height = height;
    this->width = width;
}

class Rectangle : public Area {
    public:
        Rectangle(double height, double width) : Area(height, width){};
        double getRectangleArea();
};

double Rectangle::getRectangleArea(){
    return getHeight()*getWidth();
}

class Isosceles : public Area {
    public:
        Isosceles(double height, double width) : Area(height, width){};
        double getIsoscelesArea();
};

double Isosceles::getIsoscelesArea(){
    return 0.5*getHeight()*getWidth();
}

class Cylinder : public Area {
    public:
        Cylinder(double height, double width) : Area(height, width){};
        double getCylinderArea();
};

double Cylinder::getCylinderArea(){
    return  2*M_PI*getWidth()*getWidth() + 2*M_PI*getWidth()*getHeight();
}

int main(){
    //Area a(1, 2);
    Rectangle r(1, 2);
    Isosceles i(1, 2);
    Cylinder c(1, 2);
    cout << r.getRectangleArea() << ' ' << i.getIsoscelesArea() << ' ' << c.getCylinderArea();
    return 0;
}