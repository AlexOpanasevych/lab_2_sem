#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void allocateChar(char * p){
	try
	{
		do
		{
			p = new char[1024*1024*1024]; // allocate 1 gb of memory
			if(!p) {
				throw p;
			}
		} while (p);
	}catch(const char *& p)
	{
		cerr << "ALLOC ERROR" << '\n';
		unexpected();
		return;
	}
	
}

void controlBounds(int i, int size){
	try
	{
		if(i < 0 || i >=size)
			throw i;
	}
	catch(const int & i)
	{
		cerr << "Bounds error" << '\n';
		unexpected();
		return;
	}
}


int main(){
	//char * p = nullptr;
	//allocateChar(p);
	controlBounds(10, 9);
	//delete [] p;
	return 0;
}