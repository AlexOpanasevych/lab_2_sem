#include <iostream>
#include <iomanip>
using namespace std;

class date {
 char d[9]; // store date as string : mm/dd/yy
public:
    friend istream & operator >> (istream & stream, date &d){
        return stream >> d.d;
    }
    friend ostream & operator << (ostream & stream, date &d){
        return stream << d.d;
    }
};


int main(){
    date d;
    cin >> d;
    cout << d;
    return 0;
}