/* ----------------------------------------------------------------<Header>-
 Name: 6.cpp
 Title:  Задача 3 .6.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-02-28
 Revised: ____-__-__
 Description:  Переделайте класс stack (см. Unit 2 "A more practical example"), так, чтобы в
классе, где это возможно, использовались встраиваемые функции.
 ------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

class stack
{
private:
	int tos;
	char *stck;
public:
	stack();
	~stack();
	void push(char ch);
	char pop();
};

stack::~stack()
{
	delete[] stck;
}

stack::stack()
{
	tos = 0;
	stck = new char[tos];
}

inline void stack::push(char ch)
{
	stck[tos] = ch;
	tos++;
}

inline char stack::pop(){
	if (tos == 0) cout << "Stack is empty!" << endl;
	tos--;
	return stck[tos];
}

int main()
{
	stack s;
	s.push('A');
	s.push('B');
	s.push('C');
	s.push('D');
	s.push('E');
	s.push('F');
	s.push('G');
	s.push('H');
	for (int i = 0; i < 8; i++) cout << s.pop() << endl;
	return 0;
}