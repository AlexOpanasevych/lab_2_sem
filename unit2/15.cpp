/* ----------------------------------------------------------------<Header>-
 Name: 15.cpp
 Title:  Задача 2.15.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description: Создайте новый вариант разработанного ранее класса strtype, в котором
используется конструктор с параметром (см . Unit 2 "An Example that Shows the Need for Both a
Constructor and a Destructor Function"). В вашей версии класса strtype строка получает свое
начальное значение с помощью конструктора.

 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
using namespace std;
class strtype{
    char *p;
    int len;
    int size;
    public:
        strtype(const char *ptr, int size);
        ~strtype();
        void show();
};

strtype::strtype(const char *p, int size){
    this->size = size;
    this->p = new char[size+1];
    len = strlen(p);
    if(!(this->p)) exit(EXIT_FAILURE);
    if(len > size) exit(EXIT_FAILURE);
    strcpy(this->p, p);
}

strtype::~strtype(){
    cout << "Freeing p\n";
    delete[] p;
}

void strtype::show(){
    cout << p << " length - " << len << endl;
}

int main(){
    strtype p1("test 1", 20);
    strtype p2("test 2", 20);
    p1.show();
    p2.show();
    return 0;
}