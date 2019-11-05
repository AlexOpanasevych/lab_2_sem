#include <iostream>
#include <cstring>

using namespace std;

class coord{
    int x;
    int y;
    public:
    coord(int x, int y){this->x = x; this->y = y;}
    coord & operator<<(int i);
    coord & operator>>(int i);
    void showxy(){cout << x << ' ' << y << endl;}
};

coord & coord::operator <<(int i){
    x = x << i;
    y = y << i;
    return *this;
}

coord & coord::operator >>(int i){
    x = x >> i;
    y = y >> i;
    return *this;
}

int main(){
    coord a(1, 2);
    a << 5;
    a.showxy();
    a >> 5;
    a.showxy();
    return 0;
}