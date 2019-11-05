#include <iostream>
#include <fstream>
using namespace std;

class Example{
	int i;
	public:
	void func(int new_value) const{
		// this->i = v;                 // compile error: this is a pointer to const
		const_cast<Example*>(this)->i = new_value; // OK as long as the type object isn't const
	}
	void display(){
		cout << i << endl;
	}
};

int main(){
	Example a;
	a.func(4);
	a.display();
	return 0;
}