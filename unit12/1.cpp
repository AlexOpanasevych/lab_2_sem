#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template <typename T> T min(T &a, T & b){
	return (a < b) ? a : b; 
}

int main(){
	cout << min('c', 'a') << " " << min(1, 2);
	return 0;
}