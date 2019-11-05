/* ----------------------------------------------------------------<Header>-
 Name: 16.c
 Title: Задача 2.16
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description:  Измените класс stack (см . Unit 2 "An Improved Version of the Stack class") так, чтобы
память для стека выделялась динамически. При этом длина стека должна задаваться
параметром конструктора. (Не забудьте освободить эту память с помощью деструктора!)

 ------------------------------------------------------------------</Header>-*/

#include <iostream>

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

void stack::push(char ch)
{
	stck[tos] = ch;
	tos++;
}

char stack::pop(){
	if (tos == 0) std::cout << "Stack is empty!" << std::endl;
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
	for (int i = 0; i < 8; i++) std::cout << s.pop() << std::endl;
	return 0;
}