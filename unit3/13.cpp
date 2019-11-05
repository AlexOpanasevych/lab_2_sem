/* ----------------------------------------------------------------<Header>-
 Name: 13.cpp
 Title:  Задача 3.13.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-02-28
 Revised: ____-__-__
 Description: Используя класс stack (см. Unit 2 "A more practical example"), напишите
функцию loadstack(), которая бы возвращала стек, заполненный буквами алфавита (a-z). В
вызывающей программе присвойте этот стек другому объекту и докажите, что и в этом
объекте находится алфавит. (Замечание. Удостоверьтесь, что длина стека достаточна для
хранения алфавита.)
Перегрузите функцию loadstack() так, чтобы она получала в качестве аргумента целое число
upper. В перегруженной версии, если переменная upper будет равной 1, загрузите стек
символами алфавита в верхнем регистре. В противном случае загрузите его символами
алфавита в нижнем регистре. 
 ------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

class stack
{
private:
	int tos;
	char stck[26];
public:
	stack();
	~stack();
	void push(char ch);
	char pop();
    int getTos(){return this->tos;}
    //char * getStck(){return this->stck;}
    void showStack();
};

stack loadStack(){
    stack tmp;
    //if((sizeof(stck)/sizeof(stck[0]) < 25)) return;
    for(int i = 97; i < 97+26; i++)
        tmp.push((char)(i));
    return tmp;
}

stack loadStack(int priority){
    stack tmp;
    if(priority != 1){
        tmp = loadStack();
        return tmp;
    }
    for(int i = 65; i < 91; i++) tmp.push((char)i);
    return tmp;
}

void stack::showStack(){
    while(tos > 0){
        cout << pop() << endl;
    }
}
stack::~stack(){
	//delete[] stck;
}

stack::stack(){
	tos = 0;
	//stck = new char[26];
    //if(!stck) cout << "alloc error!!!" << endl;
}

inline void stack::push(char ch){
	stck[tos] = ch;
	tos++;
    stck[tos] = 0;
}

inline char stack::pop(){
	if (tos == 0) cout << "Stack is empty!" << endl;
    tos--;
	return stck[tos];
}

int main()
{
	stack s1;
    stack s2;
    s2 = loadStack(1);
    s2.showStack();
    s2 = loadStack(100);
    s2.showStack();
	return 0;
}