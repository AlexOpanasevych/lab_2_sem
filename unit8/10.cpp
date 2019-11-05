#include <iostream>
using namespace std;

class planet
{
  protected:
    double distance; // miles from the sun
    int revolve;     // in days
  public:
    planet(double d, int r)
    {
        distance = d;
        revolve = r;
    }
};

class earth : public planet
{
    const double pi = 3.1416;
    double circumference; // circumference(окружность) of orbit
  public:
    earth(double d, int r) : planet(d, r){
        circumference = 2*r * pi;
    }
    void show(){
        cout << "Circumference of Earth is - " << circumference << endl;
    }
};

int main()
{
    earth obj(93000000, 365);
    obj.show();
    return 0;
}