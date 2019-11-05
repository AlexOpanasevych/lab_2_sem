/* ----------------------------------------------------------------<Header>-
 Name: 10.cpp
 Title: Задача 3.10
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-02-28
 Revised: ____-__-__
 Description:   Придумайте пример программы, в которой, как и при неправильном
освобождении динамической памяти, возвращать объект из функции было бы также
ошибочно.
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>

using namespace std;

class cls{
    char *string;
    public:
        cls(char *str);
        ~cls();
        cls();
        cls returnError(cls data);
        char * getStr(){return string;}
};

cls::cls(){
    cls(" ");
}
cls::cls(char *str){
    string = new char[80];
    if(!string) cout << "Alloc err" << endl;
    strcpy(string, str);
}

cls::~cls(){
    cout << "Deleting string" << endl;
    delete[] string;   
}

cls cls::returnError(cls data){
    cls temp = data;
    //temp.string = data.string;
    return temp;
}
int main(){
    cls a("a");
    cls b = a.returnError(a);
    cout << b.getStr() << endl;
    return 0;
}

// It's a bad program, so don't use it seriously :)
// при присваивании обьектов класса копируется указатель на одну и ту же строку,
// когда вызывается деструктор, он освобождает два указателя, тогда происходит сбой стэка