#include <iostream>
#include <cstdlib>
#include <typeinfo>
using namespace std;
class Shape
{
public:
    virtual void example() = 0;
};
class Rectangle : public Shape
{
public:
    void example()
    {
        cout << "*****\n*   *\n*   *\n*****\n";
    }
};
class Triangle : public Shape
{
public:
    void example()
    {
        cout << "*\n* *\n*  *\n*****\n";
    }
};
class Line : public Shape
{
public:
    void example()
    {
        cout << "*****\n";
    }
};
class NullShape : public Shape
{
public:
    void example() {}
};
// A factory for objects derived from Shape:
Shape *generator()
{
    switch (rand() % 4)
    {
        case 0:
            return new Line;
        case 1:
            return new Rectangle;
        case 2:
            return new Triangle;
        case 3:
            return new NullShape;
    }
    return nullptr;
}

int main()
{
    Shape *p;
    for (int i = 0; i < 10; i++)
    {
        p = generator(); // get next object
        cout << " class " << typeid(*p).name() << endl;
        // draw object only if it is not a NullShape
        if (p != dynamic_cast <NullShape*>(p))
            p->example();
    }
    return 0;
}