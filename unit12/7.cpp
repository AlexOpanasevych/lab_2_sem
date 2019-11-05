#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template <typename T> T sumOfElem(T * array, int size, T sum){
	if (!(size < 0))
	{
		sum += array[size];
	}
	else
	{
		return sum;
	}
	return sumOfElem(array, size - 1, sum);
}

int main(){
	int array[] = {2, 2, 2, 3, 4, 2, 1, 1};
	float array1[] = {2.1, 3.2, 4.3, 5.4, 6.5, 7.6, 8.7, 9.8};
	int n = sizeof(array)/sizeof(array[0]);
	cout << sumOfElem(array, n, 0) << endl;
	n = sizeof(array1)/sizeof(array1[0]);
	cout << sumOfElem(array1, n, 0.0f) << endl;
	return 0;
}