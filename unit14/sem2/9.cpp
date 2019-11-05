#include <iostream>
#include <cstring>
#include <strstream>

using namespace std;

void copyArray(char * Dest, const char * Src){
	ostrstream buf(Dest, strlen(Src) + 1);
	buf << Src;
}


int main(){
	char * array = new char[20];
	const char * array2 = "o, hello there :)";
	copyArray(array, array2);
	cout << array;
	return 0;
}