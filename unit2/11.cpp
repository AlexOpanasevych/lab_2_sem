/* ----------------------------------------------------------------<Header>-
 Name: 11.cpp
 Title: Задача 2.11
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description: Создайте свою функцию sleep(), приостанавливающую работу компьютера на
столько секунд, сколько указано в аргументе функции. Перегрузите sleep() так, чтобы она могла
вызываться или с целым, или со строкой, задающей целое. Например, оба этих вызова должны
заставить компьютер остановиться на 10 секунд:
sleep(10);
sleep("10");
Продемонстрируйте работу ваших функций, включив их в короткую программу. 

 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <ctime>
using namespace std;

void sleep(const size_t seconds){
    clock_t start=clock();
    while((double)(clock()-start)/CLOCKS_PER_SEC < seconds);
}

void sleep(const char * seconds){
    clock_t start = clock();
    while((double)(clock()-start)/CLOCKS_PER_SEC < atoi(seconds));
}

int main(void){
    for(size_t i = 0; i < 10; i++){
        sleep(1);
        cout << i + 1 << " ";
    }
    sleep("10");
    return 0;
}