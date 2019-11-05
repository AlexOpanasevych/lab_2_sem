#include <iostream>
#include <algorithm>
using namespace std;

template<typename T> T findMost(T * arr, int size){
	sort(arr, arr + size);
	int max_count = 1, curr_count = 1; T res = arr[0]; 
    for (int i = 1; i < size; i++) { 
        if (arr[i] == arr[i - 1]) 
            curr_count++; 
        else { 
            if (curr_count > max_count) { 
                max_count = curr_count; 
                res = arr[i - 1]; 
            } 
            curr_count = 1; 
        } 
    } 
  
    // If last element is most frequent 
    if (curr_count > max_count) 
    { 
        max_count = curr_count; 
        res = arr[size - 1]; 
    } 
  
    return res; 
}

int main(){
	int array[] = {2, 2, 2, 3, 4, 2, 1, 1};
	char array1[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c', 'c'};
	int n = sizeof(array)/sizeof(array[0]);
	cout << findMost(array, n) << endl;
	n = sizeof(array1)/sizeof(array1[0]);
	cout << findMost(array1, n);
	return 0;
}