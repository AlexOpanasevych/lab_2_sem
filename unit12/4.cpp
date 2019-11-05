#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template <typename T> class Input{
	T data;
	public:
	Input(const char * prompt, T & min_value, T & max_value){
		do
		{
			cout << prompt;
			cin >> data;
		} while (data < min_value || data > max_value);
	}
	void show(){
		cout << data;
	}
};


int main(){
	int min_value = 0, max_value = 10;
	Input <int>obj("Input data please between 0 and 10: ", min_value, max_value);
	obj.show();
	return 0;
}