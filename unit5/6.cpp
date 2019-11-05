/* ----------------------------------------------------------------<Header>-
 Name: 6.cpp
 Title: Задача 5 .6.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-03-15
 Revised: ____-__-__
 Description: Создайте класс для хранения своего имени и номера телефона.
Используя оператор new, динамически выделите память для объекта этого класса и
введите имя и телефон в соответствующие поля внутри объекта.
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
using namespace std;

class numAndName{
    char *myName;
    char *phonenumber;
    public:
        numAndName(char const *phonenumber, char const *myName);
        ~numAndName();
        char * getName() {return myName;}
        char * getNumber() {return phonenumber;}
};

numAndName::numAndName(const char *phonenumber, const char *myName) {
    this->myName = new char[strlen(myName)];
    this->phonenumber = new char[strlen(phonenumber)];
    if(!myName || !phonenumber) exit(EXIT_FAILURE);
    memcpy(this->myName, myName, strlen(myName));
    memcpy(this->phonenumber, phonenumber, strlen(phonenumber));
}

numAndName::~numAndName(){
    delete [] myName;
    delete [] phonenumber;
}

int main(){
    numAndName *a = new numAndName("380988939601", "Olexandr Opanasevych");
    cout << a->getName() << endl << a->getNumber();
    //delete a;
    return 0;
}