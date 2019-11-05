#include <iostream>

using namespace std;

class coord{
	int x, y;
public:
	coord() { x = 0; y = 0; }
	coord(int i, int j) { x = i; y = j; }
	void get_xy(int &i, int &j) { i = x; j = y; }
	coord operator +(const coord &obj);
	coord operator +();
};

coord coord::operator +(const coord &obj){
	coord temp;
	temp.x = x + obj.x;
	temp.y = y + obj.y;
	return temp;
}

coord coord::operator +(){
	if (x<0 && y<0){
		x = -x;
		y = -y;
	}
	if (x<0 && y>0){
		x = -x;
	}
	if (x>0 && y<0){
		y = -y;
	}
	return *this;
}

int main(){
	coord obj1(10, 10), obj2(5, 2), obj3, obj4(-10, 10);
	int x, y;
	obj3 = obj1 + obj2;
	obj3.get_xy(x, y);
	cout << "Adding: " << x << ' ' << y << endl;
	obj4 = +obj4;
	obj4.get_xy(x, y);
	cout << "Minus to plus: " << x << ' ' << y << endl;
	return 0;
}