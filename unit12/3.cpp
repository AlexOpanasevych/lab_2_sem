#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int SIZE = 100;

template <typename StackType> class Stack
{
	StackType stck[SIZE]; // holds the stack
	int tos;			  // index of top of stack
public:
	void init(){
		tos = 0;
	}			 // initialize stack
	void push(StackType ch); // push object on stack
	StackType pop();		 // pop object from stack
};
template <class StackType>
void Stack<StackType>::push(StackType obj)
{
	stck[tos] = obj;
	tos++;
}
template <class StackType>
StackType Stack<StackType>::pop(){
	tos--;
	return stck[tos]; 
}

int main()
{
	Stack <int> stack1;
	for (int i = 0; i < 20; i++)
	{
		stack1.push(i);
	}
	for (int i = 0; i < 20; i++)
	{
		cout << stack1.pop() << ' ';
	}
	return 0;
}