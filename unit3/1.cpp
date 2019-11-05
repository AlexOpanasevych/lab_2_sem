/* ----------------------------------------------------------------<Header>-
 Name: 1.cpp
 Title: Задача 3.1.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-02-28
 Revised: ____-__-__
 Description:  Программа (см. Unit 3 "An example of class inheritance"), которая определяет
общий базовый класс Fruit, описывающий некоторые характеристики фруктов. Этот класс
наследуется двумя производными классами Apple и Orange. Эти классы содержат
специальную информацию о конкретном фрукте (яблоке или апельсине). Требуется
расширить программу, перегрузив методы seto и seta, таким образом, чтобы их вызовы
выглядели вот так:
int main() {
 Apple a2;
 Orange o2;
 a2.seta("Jonathan", red, yes, no, yes);
 o2.seto("Valencia", orange, yes, yes, no);
 ...

 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>

using namespace std;

enum color{red, yellow, green, orange};
enum choose{yes, no};
void out(enum choose x);
void out(bool x);
char const *c[] = {"red", "yellow", "green", "orange"};

class Fruit{
public:
	enum choose annual;
	enum choose perennial;
	enum choose tree;
	enum choose tropical;
	enum color clr;
	char name[40];
};

class Apple: public Fruit {
	enum choose cooking;
	enum choose crunchy;
	enum choose eating;
public:
	void seta(char const *n, enum color c, enum choose ck, enum choose crchy, enum choose e);
	void show();
};

class Orange: public Fruit {
	enum choose juice;
	enum choose sour;
	enum choose eating;
public:
	void seto(char const *n, enum color c, enum choose j, enum choose sr, enum choose e);
	void show();
};

void out(enum choose x){
	cout << ((x == no)? "no" : "yes") << endl;
}

void out(bool x){
    cout << ((x == false) ? "no" : "yes") << endl;
}

void Apple::seta(char const *n, enum color c, enum choose ck, enum choose crchy, enum choose e){
	strcpy(name, n);
	annual = no;
	perennial = yes;
	tree = yes;
	tropical = no;
	clr = c;
	cooking = ck;
	crunchy = crchy;
	eating = e;
}

void Orange::seto(char const *n, enum color c, enum choose j, enum choose sr, enum choose e){
	strcpy(name, n);
	annual = no;
	perennial = yes;
	tree = yes;
	tropical = yes;
	clr = c;
	juice = j;
	sour = sr;
	eating = e;
}

void Apple::show(){
	cout << name <<" apple is: " << endl;
	cout << "Annual: "; out(annual);
	cout << "Perennial: "; out(perennial);
	cout << "Tree: "; out(tree);
	cout << "Tropical: "; out(tropical);
	cout << "Color: " << c[clr] << endl;
	cout << "Good for cooking: "; out(cooking);
	cout << "Crunchy: "; out(crunchy);
	cout << "Good for eating: "; out(eating);
	cout << endl;
}

void Orange::show(){
	cout << name <<" orange is: " << endl;
	cout << "Annual: "; out(annual);
	cout << "Perennial: "; out(perennial);
	cout << "Tree: "; out(tree);
	cout << "Tropical: "; out(tropical);
	cout << "Color: " << c[clr] << endl;
	cout << "Good for juice: "; out(juice);
	cout << "Sour: "; out(sour);
	cout << "Good for eating: "; out(eating);
}



int main(){
    Apple a2;
    Orange o2;
    a2.seta("Jonathan", red, yes, no, yes);
    o2.seto("Valencia", orange, yes, yes, no);
    a2.show();
    o2.show();
    return 0;
}