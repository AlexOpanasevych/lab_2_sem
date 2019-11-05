/* ----------------------------------------------------------------<Header>-
 Name: 1.cpp
 Title: Задача 2.1
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description: Напишите программу для ввода количества отработанных персоналом часов и
размера почасовой оплаты каждого. Затем выведите суммарную зарплату персонала.
(Удостоверьтесь в правильности ввода.)

 ------------------------------------------------------------------</Header>-*/

#include <iostream>
using namespace std;

int main(){
    int time = 1, sum, salary;
    while(time != 0 && time > 0){
        if(time != 0 && time > 0){
            cout << "Input time of job and salary per hour(like this : <time> <salary>) (0 to quit):" << endl;
            cin >> time >> salary;
            cout << "Your salary is : "<< time*salary << endl;
            sum += time;
        }
    }
    cout << "Sum of salaries is :" << sum*salary;
    cin.get();
    return 0;
}