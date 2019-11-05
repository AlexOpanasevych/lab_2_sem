/* ----------------------------------------------------------------<Header>-
 Name: 11.cpp
 Title:  Задача 3.11.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-02-28
 Revised: ____-__-__
 Description:  Представьте себе ситуацию, в которой показанные ниже два класса рг1 и рг2
используют общий принтер. Для оставшейся части программы необходимо знать, когда
принтер занят объектом одного из этих классов. Создайте функцию inuse(), которая
возвращает true, когда принтер занят объектом одного из классов и false - в противном
случае. Сделайте эту функцию дружественной как классу pr1, так и классу рг2.
class pr1 {
 int printing;
 // ...
public:
 pr1() { printing = 0; }
 void set_print(int status) { printing = status; }
 // ...
};
class pr2 {
 int printing;
 // ...
public:
 void set_print(int status) { printing = status; }
  // ...
};
 ------------------------------------------------------------------</Header>-*/

#include <iostream>

using namespace std;

class pr2;
class pr1 {
	int printing;
	// ...
public:
	pr1() { printing = 0; }
	void set_print(int status) { printing = status; }
	friend bool inuse(pr1, pr2);
};

class pr2 {
	int printing;
	// ...
public:
	pr2() { printing = 0; }
	void set_print(int status) { printing = status; }
	friend bool inuse(pr1, pr2);
};

bool inuse(pr1 p1, pr2 p2){
	return (p1.printing == 1 || p2.printing == 1 ? true : false);
}

int main(){
	pr1 p1; 
    pr2 p2;
	cout << (inuse(p1, p2) ? "Printer is used" : "Printer is free") << endl;
    p2.set_print(1);
    cout << (inuse(p1, p2) ? "Printer is used" : "Printer is free") << endl;
	return 0;
}