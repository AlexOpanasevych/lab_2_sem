#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

template <typename T> int findElem(const T & object, const T *list, int size) {
	int i;
	for (i = 0; i < size; i++)
	{
		if (list[i] ==object)
		{
			return i;
		}
	}
	return -1;
}


int main(){
	const char str[] = "Ilon Musk";
	int n = sizeof(str)/sizeof(str[0]);
	int numbers[] = {1, 2, 3, 4, 5, 6};
	if(findElem('M', str, n) != -1) cout << "Element 'M' is presented at index: " << findElem('M', str, n) << endl;
	n = sizeof(numbers)/sizeof(numbers[0]);
	if(findElem(4, numbers, n) != -1) cout << "Element 4 is presented at index: " << findElem(4, numbers, n);
	return 0;
}