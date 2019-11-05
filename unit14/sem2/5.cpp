#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
static int counter = 0;
class count{
	//int count;
	public:
	count(){
		cout << ++counter << endl;
	}
	~count(){
		cout << --counter << endl;
	}
};

int main(){
	count c1;
	count c2;
	count c3;
	count c4;
	return 0;
}