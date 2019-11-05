#include <iostream>
using namespace std;

class INT{
    int a, lowest_div;
    public:
    friend ostream & operator<<(ostream &stream, INT &obj){
        return stream << "Int : " << obj.a << endl << "Lowest div : " << obj.lowest_div << endl;
    }
    friend istream & operator>>(istream &stream, INT &obj){
        stream >> obj.a;
        for(int i = obj.a; i >= 1; i--){
            if(obj.a % i == 0){
                obj.lowest_div = i;
            }
        }
        return stream;
    }
};

int main(){
    INT a;
    cin >> a;
    cout << a;
    return 0;
}