#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

void parseFile(){
	string line;
	ifstream takeData("C:/Users/Саня/source/repos/WCII-test3/WCIIRemake/units/berserker.unit");
	while(getline(takeData, line)){
		cout << line;
		string token;
		
	}
}

int main(){parseFile(); return 0;}