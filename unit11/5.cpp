#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Num{
	private:
	public:
	virtual void shownum(int i);
};

class outhex : public Num{
	public:
	void shownum(int i){
		cout << hex << i << endl;
	}
};

class outoct : public Num{
	public:
	void shownum(int i){
		cout << oct << i << endl;
	}
};


int main(){
	outhex h;
	h.shownum(10);
	outoct o;
	o.shownum(8);
	return 0;
}