#include <iostream>

using namespace std;

class array{
    int * arr;
    int size;
    public:
        array(int size);
        ~array(){delete [] arr;}
        int & operator [](int i);
};

array::array(int size){
    if(size < 1){exit(1);}
    this->size = size;
    arr = new int[size];
    if(!arr){exit(1);}
}

int & array::operator [](int i){
    if(i < 0 || i>=size) {
        cout << "Bounds error" << endl;
        exit(1);
    }
    return arr[i];
}

int main(){
    array a(10);
    a[5] = 4;
    a[1] = 3;
    cout << a[1] << ' ' << a[5] << endl;
    a[10] = 5;
    return 0;
}