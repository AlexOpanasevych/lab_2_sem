/* ----------------------------------------------------------------<Header>-
 Name: 14.cpp
 Title: 
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-03-15
 Revised: ____-__-__
 Description:  В Unit2 была создана программа с классом strtype, в которой память
для строки выделялась динамически. Переделайте эту программу так, чтобы в ней
использовались операторы new и delete.
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
using namespace std;

class strtype{
    char *p;
    int len;
    int size;
    public:
        strtype(const char *ptr);
        ~strtype();
        void show();
};

strtype::strtype(const char *p){
    this->size = strlen(p);
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
    strtype p1("test 1");
    strtype p2("test 2");
    p1.show();
    p2.show();
    return 0;
}