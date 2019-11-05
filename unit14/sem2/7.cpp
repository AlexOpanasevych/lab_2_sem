#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class myclass
{
	int a;

public:
	myclass(int x) { a = x; }
	myclass(const char *str) { a = atoi(str); }
	int geta() { return a; }
};
int main()
{
	myclass obj1 = 4;
	myclass obj2 = "123 ";
	cout << "obj1 : " << obj1.geta() << endl;
	cout << "obj2 : " << obj2.geta() << endl;
	return 0;
}