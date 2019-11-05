#include <iostream>

using namespace std;

class increment {
    int x;
    public:
    increment(int i = 0) { x = i;}
    int &ref = x;
    void get_xy(int i){i = x;}
    friend increment operator ++(increment &obj);
    friend increment operator ++(increment &obj, int notused);
};

increment operator ++(increment &obj){
    obj.x++;
    return obj;
}

increment operator ++(increment &obj, int notused){
    obj.x++;
    return obj;
}

int main(){
    increment a;
    for(int i = 0; i < 20; i++){
        a++;
        cout << a.ref << ' ';
    }
}