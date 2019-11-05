/* ----------------------------------------------------------------<Header>-
 Name: 7.cpp
 Title:  Задача 5.7.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-03-15
 Revised: ____-__-__
 Description:  В новую версию программы Example 5.11 (см. Unit 5 "More About new
And delete") добавьте деструктор и удостоверьтесь (продемонстрируйте в
программе), что при освобождении памяти, обозначенной указателем рtr, для
каждого элемента массива (по разу на каждый элемент массива) вызывается
деструктор.
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
using namespace std;

class samp{
    int a, b;
    public:
        void set_ij(int a, int b) {this->a = a; this->b = b;}
        ~samp();
        int get_product() {return a*b;}
};

samp::~samp(){
    cout << " Destructing... " << endl;
}

int main(){
    samp *ptr = new samp[10];
    if(!ptr) {return -1;}
    for(int i = 0; i < 10; i++) ptr[i].set_ij(i, i);
    for(int i = 0; i < 5; i++){
        cout << "Product[" << i << "] is: ";
        cout << ptr[i].get_product() << '\n';
    }
    delete [] ptr;
    return 0;
}