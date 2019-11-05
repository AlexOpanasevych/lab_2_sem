#include <iostream>
using namespace std;

class array {
 int nums[10];
public:
    array();
    void set(int n[10]);
    void show();
    friend array operator +(array &obj1, array &obj2);
    friend array operator -(array &obj1, array &obj2);
    friend int operator ==(array &obj1, array &obj2);
};

array::array() {
    for (int i=0; i <10; i++) nums[i] = 0;
}

void array::set(int *n) {
    for (int i=0; i<10; i++) nums[i] = n[i];
}

void array::show() {
    for (int i=0; i<10; i++)
    cout << nums[i] << ' ';
    cout << "\n";
}

array operator +(array &obj1, array &obj2){
    array obj3;
    for(int i = 0; i < 10; i++){
        obj3.nums[i] = obj1.nums[i] + obj2.nums[i];
    }
    return obj3;
}

array operator -(array &obj1, array &obj2){
    array obj3;
    for(int i = 0; i < 10; i++){
        obj3.nums[i] = obj1.nums[i] - obj2.nums[i];
    }
    return obj3;
}

int operator ==(array &obj1, array &obj2){
    for(int i = 0; i < 10; i++){
        if(obj1.nums[i] != obj2.nums[i]) return 0;
    }
    return 1;
}

int main() {
    array obj1, obj2, obj3;
    int i[10] = {1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10};
    obj1.set(i);
    obj2.set(i);
    obj3 = obj1 + obj2;
    obj3.show();
    obj3 = obj1 - obj3;
    obj3. show();
    if (obj1 == obj2)
    cout << "obj1 equals obj2\n";
    else
    cout << "obj1 does not equal obj2\n";
    if (obj1 == obj3)
    cout << "obj1 equals obj3\n";
    else
    cout << "obj1 does not equal obj3\n";
    return 0;
}