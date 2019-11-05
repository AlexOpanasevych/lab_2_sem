#include <iostream>

template <typename T> T myabs(T a){
	return (a < 0) ? (-1)*a : a;
}


using namespace std;
int main(){
	cout << myabs(-10.3280) << endl;
	cout << myabs(-100) << endl;
	cout << myabs(-1*'a');
	return 0;
}