#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

class Date{
    int d, m, y;
    public:
        Date(int d, int m, int y){
            this->d = d;
            this->m = m;
            this->y = y;
        }
        Date(const char *str){
            sscanf(str, "%d/%d/%d", &d, &m, &y);
        }
        Date(time_t time){
            tm* now = localtime(&time);
            y = (int)(now->tm_year + 1900);
            m = (int)(now->tm_mon + 1);
            d = (int)(now->tm_mday);
        }
        void show(){
            cout << d << '/' << m << '/' << y << '\n';
        }
};

int main() {
    Date date(time(0));
    date.show();
    Date date2("01/04/2019");
    date2.show();
    return 0;
}