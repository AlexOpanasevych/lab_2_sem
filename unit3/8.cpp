/* ----------------------------------------------------------------<Header>-
 Name: 8.cpp
 Title: Задача 3 .8.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-02-28
 Revised: ____-__-__
 Description:  Используя класс stack (см. Unit 3 Example 3.7) добавьте в программу функцию
showstack(), которой в качестве аргумента передается объект типа stack. Эта функция
должна выводить содержимое стека на экран.
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
    int getTos(){return this->tos;}
};
inline void showStack(stack &a){
    while(a.getTos() > 0){
        cout << a.pop() << endl;
    }
}
stack::~stack(){
	delete[] stck;
}

stack::stack(){
	tos = 0;
	stck = new char[tos];
}

inline void stack::push(char ch){
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
    showStack(s);
	return 0;
}