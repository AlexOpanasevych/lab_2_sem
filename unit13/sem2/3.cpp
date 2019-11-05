#include <iostream>
#include <typeinfo>
#include <cmath>
#include <cstdlib>
using namespace std;
template <class T> class Num
{
public:
	T x;
	Num(T i) { x = i; }
	virtual T get_val() { return x; }
};
template <class T> class Square : public Num<T>
{
public:
	Square(T i) : Num<T>(i) {}
	T get_val() { return this->x * this->x; }
};
template <class T> class Sqr_root : public Num<T>
{
public:
	Sqr_root(T i) : Num<T>(i) {}
	T get_val() { return sqrt((double)this->x); }
};
// A factory for objects derived from Num:
Num <double> *generator()
{
	switch (rand() % 2)
	{
		case 0:
			return new Square<double>(rand() % 100);
		case 1:
			return new Sqr_root<double>(rand() % 100);
	}
	return NULL;
}

int main()
{
	Num<double> obj1(10), *p1;
	Square<double> obj2(100.0), *p2;
	Sqr_root<double> obj3(999.2), *p3;
	//Num <int> *ptrb;
	//Square <double> *ptrd;
	//ptrd = dynamic_cast <Num<int>*> (ptrb);
	cout << "Generate some objects.\n";
	for (int i = 0; i < 10; i++)
	{
		p1 = generator();
		p2 = dynamic_cast<Square<double> *>(p1);
		if (p2)
			cout << "Square object: ";
		p3 = dynamic_cast<Sqr_root<double> *>(p1);
		if (p3)
			cout << "Sqr_root object: ";
		cout << "Value is: " << p1->get_val();
		cout << endl;
	}
	return 0;
}

// нет, поскольку аргументы имеют разный классовый тип (нам и сквер)