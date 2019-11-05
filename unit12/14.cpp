#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template <typename T> class array{
    T * arr;
    int size;
    public:
        array(int size);
        ~array(){delete [] arr;}
        T & operator [](int i);
};

template<typename T>array<T>::array(int size){
    if(size < 1){exit(1);}
    this->size = size;
    arr = new T[size];
    if(!arr){exit(1);}
}

template <typename T> T & array<T>::operator [](int i){
    if(i < 0 || i>=size) {
        cout << "Bounds error" << endl;
        exit(1);
    }
    return arr[i];
}

int main(){
    array <int>a(10);
    a[5] = 4;
    a[1] = 3;
    cout << a[1] << ' ' << a[5] << endl;
    //a[10] = 5;
	array <char> b(10);
    b[0] = 'a'; b[1] = 'b';
    cout << b[0] << ' ' << b[1] << endl;
	b[15] = 'z';
    return 0;
}