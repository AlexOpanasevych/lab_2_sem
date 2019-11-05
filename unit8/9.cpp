#include <iostream>
using namespace std;

class building{
    int floors, rooms, area;
    public:
    building(int f, int r, int a){
        cout << "Constructing building..." << endl;
        this->floors = f;
        this->rooms = r;
        this->area = a;
    }
    void show(){
        cout << floors << ' ' << rooms << ' ' << area << '\n';
    }
};

class house : virtual public building{
    int bathrooms, bedrooms;
    public:
    house(int f, int r, int a, int btr, int br) : building(f, r, a){
        cout << "Constructing house..." << endl;
        this->bathrooms = btr;
        this->bedrooms = br;
    }
    void show(){
        cout << "House - " <<  bathrooms << ' ' << bedrooms;
        building::show();
    }
};

class office : virtual public building{
    int fire_extinguishers, phones;
    public:
    office(int f, int r, int a, int fe, int ph) : building(f, r, a){
        cout << "Constructing office..." << endl;
        this->fire_extinguishers = fe;
        this->phones = ph;
    }
    void show(){
        cout << "Office - " << fire_extinguishers << ' ' << phones << endl;
        building::show();
    }
};

int main(){
    office o(2, 10, 100, 5, 6);
    house h(3, 12, 200, 2, 2);
    o.show();
    h.show();
    return 0;
}