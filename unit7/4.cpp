#include <iostream>

using namespace std;

class coord{
	int x, y;
public:
	coord() { x = 0; y = 0; }
	coord(int i, int j) { x = i; y = j; }
	void get_xy(int &i, int &j) { i = x; j = y; }
	int operator >(const coord &obj);
	int operator <(const coord &obj);
};

int coord::operator >(const coord &obj){
	return x > obj.x && y > obj.y;
}

int coord::operator <(const coord &obj){
	return x < obj.x && y < obj.y;
}

int main(){
	coord obj1(10, 10), obj2(5, 2), obj3(20, 20);
	if (obj1 > obj2) {
		cout << "obj1 > obj2" << endl;
	} else {
		cout << "obj1 < obj2" << endl;
	}
	if (obj3 < obj1) {
		cout << "obj3 < obj1" << endl;
	} else {
		cout << "obj3 > obj1" << endl;
	}
}