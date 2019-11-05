#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Example{
	int value;
	public:
	Example(int arg){value = arg;} // при инициализации
	/*Example & operator =(int value){ // после инициализации
		this->value = value;
		return *this;
	}*/

	operator int(){ // преобразование в целоч. тип
		return value;
	}
	Example(const string arg){value = stoi(arg);} 
};

int main(){
	string ex = "123";
	Example a = 10; //is not allowed, because we work with class and must to overload cast operator
	Example b = 5.6;
	a = 10;
	a = ex;
	//cout << (long)a << endl;
	cout << a << ' ' << b << endl;
	return 0;
}