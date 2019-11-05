#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Dist{
	double distance;
	public:
	virtual void trav_time(double distance){
		this->distance = distance;
		cout << this->distance/60 << " hours(speed 60 miles per hour)" << endl;
	}
};

class Metric : public Dist{
	double distance;
	public:
	void trav_time(double distance){
		this->distance = distance;
		cout << this->distance/100 << " hours(speed 100 kms per hour)"<< endl;
	}
};




int main(){
	Dist d;
	d.trav_time(1000.50);
	Metric m;
	m.trav_time(2000.30);
	return 0;
}