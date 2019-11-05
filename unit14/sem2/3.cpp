#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

class Pwr
{
	int base;
	int exp;

public:
	Pwr(int b, int e)
	{
		base = b;
		exp = e;
	}
	// create conversion to integer here
	operator int()
	{
		return (int)pow(base, exp);
	}
};

int main()
{
	Pwr number(3, 4);
	cout << (int)number << endl;
	return 0;
}