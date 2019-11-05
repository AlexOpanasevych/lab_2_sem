#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

double divide (double a, double b) {
	try
	{
		if(b == 0){
			throw b;
		}
	}
	catch(double b)
	{
		cerr << "Divide by zero!!!" << '\n';
		return 0;
	}
 	return a/b;
}

int main(){
	cout << divide(5, 0);
	return 0;
}