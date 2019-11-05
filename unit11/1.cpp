#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ostream & highE(ostream & stream){
	stream.setf(ios::scientific | ios::uppercase);
	return stream;
}


int main(){
	cout << highE << 2.937284;
	return 0;
}