#include <iostream>
#include <cstring>

using namespace std;

class three_d {
    int x, y, z;
public:
    three_d(int i, int j, int k) { x=i; y=j; z=k; }
    int &ref1 = x;
    int &ref2 = y;
    int &ref3 = z;
    three_d(){ x=0; y=0; z=0; }
    void get(int &i, int &j, int &k) { i=x; j=y; k=z; }
    void showxyz(){cout << x << ' ' << y << ' ' << z << endl;}
    three_d operator +(three_d & a){
        three_d b;
        b.ref1 = x + a.ref1;
        b.ref2 = y + a.ref2;
        b.ref3 = z + a.ref3;
        return b;
    }
    three_d operator =(three_d a){
        x = a.ref1;
        y = a.ref2;
        z = a.ref3;
        return *this;
    }
    three_d operator -(three_d & a){
        three_d b;
        b.ref1 = x - a.ref1;
        b.ref2 = y - a.ref2;
        b.ref3 = z - a.ref3;
        return b;
    }
    three_d operator --(int){
        x--;
        y--;
        z--;
        return *this;
    }
    three_d operator ++(int){
        x++;
        y++;
        z++;
        return *this;
    }
    int operator ==(three_d & a){
        return (x == a.x) && (y == a.y) && (z == a.z);
    }
    int operator !=(three_d & a){
        return (x != a.x) && (y != a.y) && (z != a.z);
    }
    int operator ||(three_d & a){
        return (x || a.x) && (y || a.y) && (z || a.z);
    }
    three_d operator +(int a){
        three_d b;
        b.ref1 = x + a;
        b.ref2 = y + a;
        b.ref3 = z + a;
        return b;
    }
    friend three_d operator +(int c, three_d & a){
        three_d b;
        b.ref1 = a.x + c;
        b.ref2 = a.y + c;
        b.ref3 = a.z + c;
        return b;
    }
};



int main(){
    three_d a(1, 2, 3);
    three_d b(1, 2, 3);
    three_d c(1, 2, 3);
    a = a + b;
    a.showxyz();
    a++;
    a.showxyz();
    a--;
    a.showxyz();
    a--;
    a.showxyz();
    three_d d = 10 + a;
    three_d f = a + 10;
    if (c == b) cout << "it's equals" << endl;
    if (a || b) cout << "it not equals" << endl;
    d.showxyz();
    f.showxyz();
    return 0;
}