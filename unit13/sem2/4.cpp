#include <iostream>
using namespace std;
void f(const double &i)
{
	const_cast <double &> (i) = 100;
}

int fun(int* ptr)
{ 
    return (*ptr + 10); 
}

class student 
{ 
private: 
    int roll; 
public: 
    // constructor 
    student(int r):roll(r) {} 
  
    // A const function that changes roll with the help of const_cast 
    void fun() const
    { 
        ( const_cast <student*> (this) )->roll = 5; 
    } 
  
    int getRoll()  { return roll; } 
}; 

class coords{
    int x, y;
    const int z = 0;
    public:
    coords(int _x, int _y) : x(_x), y(_y){}
    void add(int newX, int newY, int newZ){
        x = newX;
        y = newY;
        const int * ptr = &z;
        //const_cast<int*>(ptr) = newZ;
    }
};
  
int main()
{
	double x = 98.6;
	cout << x << endl;
	f(x);
	cout << x << endl;
	student s(3); 
    cout << "Old roll number: " << s.getRoll() << endl; 
  
    s.fun(); 
  
    cout << "New roll number: " << s.getRoll() << endl; 
	const int val = 10; 
    const int *ptr = &val; 
    int *ptr1 = const_cast <int *>(ptr); 
    cout << fun(ptr1); 
	return 0;
}