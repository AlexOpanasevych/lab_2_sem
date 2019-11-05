/* ----------------------------------------------------------------<Header>-
 Name: 17.cpp
 Title: Задача 2.17.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description: Создайте класс time_and_date, которому при его создании передается текущее
системное время и дата в виде параметров конструктора. Этот класс должен включать в себя
функцию-член, выводящую время и дату на экран.
 Подсказка: Для нахождения и вывода на экран этих данных воспользуйтесь стандартной
библиотечной функцией времени и даты.

 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

class timeAndDate{
    tm now;
    public:
        timeAndDate(time_t t){
            localtime_s(&now, &t);
        }
        void show();
};

void timeAndDate::show(){
    char buffTime[31 + 1];
	asctime_s(buff, &now);
	cout << buffTime << endl;
}

int main(void){
    time_t t = time(0);
    timeAndDate td(t);
    td.show();
    return 0;
}