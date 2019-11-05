#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

inline void setBait(ofstream & stream){
	stream.seekp(81, ios::beg);
}


int main(){
	ofstream out("4.txt");
	setBait(out);
	out << "I love KPI!!!";
	return 0;
}