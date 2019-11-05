#include <iostream>

using namespace std;

class coord{
	int x, y;
public:
	coord() { x = 0; y = 0; }
	coord(int i, int j) { x = i; y = j; }
	void get_xy(int &i, int &j) { i = x; j = y; }
	coord operator +(const coord &obj);
	coord operator -(const coord &obj);
	coord operator =(const coord &obj);
	coord operator *(const coord &obj);
	coord operator /(const coord &obj);
};

coord coord::operator +(const coord &obj){
	coord temp;
	temp.x = x + obj.x;
	temp.y = y + obj.y;
	return temp;
}

coord coord::operator -(const coord &obj){
	coord temp;
	temp.x = x - obj.x;
	temp.y = y - obj.y;
	return temp;
}

coord coord::operator =(const coord &obj){
	x = obj.x;
	y = obj.y;
	return *this;
}

coord coord::operator *(const coord &obj){
	coord temp;
	temp.x = x * obj.x;
	temp.y = y * obj.y;
	return temp;
}

coord coord::operator /(const coord &obj){
	coord temp;
	temp.x = x / obj.x;
	temp.y = y / obj.y;
	return temp;
}

int main(){
	coord obj1(10, 10), obj2(5, 2), obj3;
	int x, y;
	obj3 = obj1 + obj2;
	obj3.get_xy(x, y);
	cout << "Adding: " << x << ' ' << y << endl;
	obj3 = obj1 - obj2;
	obj3.get_xy(x, y);
	cout << "Subtraction: " << x << ' ' << y << endl;
	obj3 = obj1;
	obj3.get_xy(x, y);
	cout << "Assignment: " << x << ' ' << y << endl;
	obj3 = obj1 * obj2;
	obj3.get_xy(x, y);
	cout << "Multiplication: " << x << ' ' << y << endl;
	obj3 = obj1 / obj2;
	obj3.get_xy(x, y);
	cout << "Distribution: " << x << ' ' << y << endl;
	return 0;
}