#include <iostream>

using namespace std;

class coord{
	int x, y;
public:
	coord() { x = 0; y = 0; }
	coord(int i, int j) { x = i; y = j; }
	void get_xy(int &i, int &j) { i = x; j = y; }
	friend coord operator *(const coord &obj, int i);
	friend coord operator *(int i, const coord &obj);
};

coord operator *(const coord &obj, int i){
	coord temp;
	temp.x = obj.x * i;
	temp.y = obj.y * i;
	return temp;
}

coord operator *(int i, const coord &obj){
	coord temp;
	temp.x = i * obj.x;
	temp.y = i * obj.y;
	return temp;
}

int main(){
	coord obj1(10, 10), obj2;
	int x, y;
	obj2 = obj1 * 10;
	obj2.get_xy(x, y);
	cout << "Multiplication (obj1 * 10): " << x << ' ' << y << endl;
	obj2 = 5 * obj1;
	obj2.get_xy(x, y);
	cout << "Multiplication (5 * obj1): " << x << ' ' << y << endl;
	return 0;
}