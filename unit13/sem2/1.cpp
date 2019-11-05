#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T> class Coord
{
private:
	T x, y;
public:
	Coord(T x, T y);
	T getx();
	T gety();
};

template <typename T> T Coord<T>::getx(){
	return this->x;
}

template <typename T> T Coord<T>::gety(){
	return this->y;
}

template <typename T> Coord<T>::Coord(T x, T y)
{
	this->x = x;
	this->y = y;
}


int main(){
	Coord<int> a(1, 2);
	Coord<char> b('a', 'b');
	Coord <double> c (1.2, 1.3);
	Coord <float> d(1.5, 2.6);
	cout << "a -> " << a.getx() << ' ' << a.gety() << endl 
	<< "b -> " << b.getx() << ' ' << b.gety() << endl
	<< "c -> " << c.getx() << ' ' << c.gety() << endl
	<< "d -> " << d.getx() << ' ' << d.gety() << endl;
	return 0;
}