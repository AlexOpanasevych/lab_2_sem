#include <iostream>

using namespace std;

class dynarray {
 int *ptr;
 int size;
public:
    dynarray(int s){size = s; ptr = new int[size];}// pass size of array in s
    int &put(int i){if(i < 0 && i > size) exit(1); return ptr[i];} // return reference to element i
    int get(int i){if(i < 0 && i > size) exit(1); return ptr[i];} // return value of element i
    dynarray & operator = (dynarray & array){
        for(int i = 0; i < size; i++){
            ptr[i] = array.get(i);
        }
        return *this;
    }
    ~dynarray(){cout << "Deleting ..."; delete [] ptr;}
    void print(){
        for(int i = 0; i < size; i++){
            cout << ptr[i] << ' ';
        }
        cout << endl;
    }
};

int main(){
    dynarray a(10);
    for (int i = 0; i < 10; i++)
    {
        a.put(i) = i;
    }
    
    a.print();
    dynarray b(15);
    for (int i = 0; i < 15; i++)
    {
        b.put(i) = 15-i;
    }
    b.print();
    a = b;
    a.print();
}