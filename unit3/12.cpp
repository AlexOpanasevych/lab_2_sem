/* ----------------------------------------------------------------<Header>-
 Name: 12.cpp
 Title:  Задача 3.12.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-02-28
 Revised: ____-__-__
 Description:  У вас есть следующий класс:
class planet {
 int moons;
 double dist_from_sun; // in miles
 double diameter;
 double mass;
public:
 // ....
 double get_miles() { return dist_from_sun; }
};
Создайте функцию light(), получающую в качестве аргумента объект типа planet и
возвращающую число секунд, за которые свет достигает планеты. (Предположим, что
скорость света равна 186000 миль в секунду и что значение dist_from_sun, т. е. расстояние
от Солнца, задано в милях.) 
 ------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

class planet {
    int moons;
    double dist_from_sun; // in miles
    double diameter;
    double mass;
    const double milesPerSecond = 186000;
    public:
        //double light(planet a);
        planet(int dist_from_sun){this->dist_from_sun = dist_from_sun;}
        double get_miles() { return dist_from_sun; }
        double getMilesPerSecond() { return milesPerSecond; }
};

double light(planet a){
    return (a.get_miles()/a.getMilesPerSecond());
}

int main(){
    planet Earth(92960000);
    cout << "Distance from Sun " <<  light(Earth) << endl;
    return 0;
}