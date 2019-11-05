#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

template <typename T> void bubbleSort(T * array, int n){
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (array[j] > array[j+1])
			{
				auto temp = array[j];
				array[j] = array[j + 1];
				array[j+1] = temp;
			}
			
		}
	}
	
}

int main(){
	int array[] = {2, 2, 2, 3, 4, 2, 1, 1};
	float array1[] = {131.1, 32.2, 41.3, 25.4, 36.5, 17.6, 18.7, 19.8};
	char array2[] = {'z', 'x', 'q', 'r', 'n', 'l', 'k', 'a'};
	int n = sizeof(array)/sizeof(array[0]);
	bubbleSort(array, n);
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	n = sizeof(array1)/sizeof(array1[0]);
	bubbleSort(array1, n);
	for (int i = 0; i < n; i++)
	{
		cout << array1[i] << " ";
	}
	cout << endl;
	n = sizeof(array2)/sizeof(array2[0]);
	bubbleSort(array2, n);
	for (int i = 0; i < n; i++)
	{
		cout << array2[i] << " ";
	}
	cout << endl;
	return 0;
}