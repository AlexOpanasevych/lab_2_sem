/* ----------------------------------------------------------------<Header>-
 Name: 14.cpp
 Title: Задача 2.14.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description: Создайте класс stopwatch для имитации секундомера. Используйте конструктор для
начальной установки секундомера в 0. Образуйте две функции-члена start() и stop()
соответственно для запуска и остановки секундомера. Включите в класс и функцию-член show()
для вывода на экран величины истекшего промежутка времени. Также используйте деструктор
для автоматического вывода на экран времени, прошедшего с момента создания объекта класса
stopwatch , до его удаления. (Для простоты время приведите в секундах.)
(в Cygwin не выводит время, в VS Code выводит, отсчитывает точно, я проверял)
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <ctime>
#include <Windows.h>
#define MILSEC_PER_SEC 1000
using namespace std;

class StpWtch{
    clock_t startProgram;
    clock_t endOfTimer;
    clock_t startTimer;
    clock_t endOfProgram;
    public:
        int seconds;
        StpWtch();
        ~StpWtch();
        void start();
        void stop();
        void show();
};

StpWtch::StpWtch(){
    startProgram = clock();
}

void StpWtch::start(){
    cout << "Started"<< endl;
    startTimer = clock();
}

void StpWtch::stop(){
    cout << "Timer stopped!";
    endOfTimer = clock();
}

void StpWtch::show(){
    cout << "Time : " << (double)(clock() - startTimer)/(double)CLOCKS_PER_SEC << endl;
}

StpWtch::~StpWtch(){
    endOfProgram = clock();
    cout << "Elapsed time : " << (double)(endOfProgram - startProgram)/(double)CLOCKS_PER_SEC << endl;
}

int main(){
    StpWtch timer;
    cout << "Input time: ";
    cin >> timer.seconds;
    timer.start();
    Sleep(timer.seconds*MILSEC_PER_SEC);
    timer.stop();
    timer.show();
    return 0;
}