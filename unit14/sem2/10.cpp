#include <iostream>
#include <string>
#include <strstream>
using namespace std;

double convert(const char * _str){
	double value = 0;
	istrstream con(_str, sizeof(_str));
	con >> value;
	return value;
}

int main(){

	cout << convert("123.123");
	return 0;
}