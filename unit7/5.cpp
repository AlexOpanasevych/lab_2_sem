#include <iostream>

using namespace std;

class coord{
	int x, y;
public:
	coord() { x = 0; y = 0; }
	coord(int i, int j) { x = i; y = j; }
	void get_xy(int &i, int &j) { i = x; j = y; }
	coord operator --();
	coord operator --(int notused);
};

coord coord::operator --(){
	x--;
	y--;
	return *this;
}

coord coord::operator --(int notused){
	x--;
	y--;
	return *this;
}

int main(){
	coord obj(10, 10);
	int x, y;
	--obj;
	obj.get_xy(x, y);
	cout << "--obj: " << x << ' ' << y << endl;
	obj--;
	obj.get_xy(x, y);
	cout << "obj--: " << x << ' ' << y << endl;
	return 0;
}
	