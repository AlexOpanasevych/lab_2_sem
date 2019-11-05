#include <iostream>
using namespace std;

class Airship{
    int count_of_passengers;
    double ft, kg, tonna;
    public:
    Airship(){
        cout << "Constructing Airship..." << endl;
    }
};

class Airplane : public Airship{
    enum Engine{screw, reactive};
    double range_km, range_mile;
    public:
    Airplane(){
        cout << "Constructing Airplane..." << endl;
    }
};

class Balloon : public Airship{
    enum Gas{hydrogen, helium};
    double foots, meters;
    public:
    Balloon(){
        cout << "Constructing Balloon..." << endl;
    }
};

int main(){
    Airplane plane;
    Balloon loon;
    return 0;
}