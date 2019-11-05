/* ----------------------------------------------------------------<Header>-
 Name: 14.cpp
 Title:  Задача 3.14.
 Group: TI-81
 Student: Opanasevich O.B.
 Written: 2019-02-28
 Revised: ____-__-__
 Description:   Используя класс strtype (см. Unit 3 Example 3.2а), добавьте дружественную
функцию, которая получает в качестве аргумента указатель на объект типа strtype и
возвращает указатель на строку. (Таким образом, функция должна возвращать указатель
р). Назовите эту функцию get_string().

 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
using namespace std;

class strtype{
	char *string;
	int len;
public:
	strtype(const char *ptr);
	~strtype();
	void show();
	friend char * getString(strtype *string);
};
strtype::strtype(const char *ptr){
	len = strlen(ptr);
	string = new char[len+1];
	if (!string)
	{
		cout << "Alloc error" << endl;
		exit(EXIT_FAILURE);
	}
	strcpy(string, ptr);
}

strtype::~strtype(){
	delete[] string;
}
char * getString(strtype * string){
    return string->string;
}

int main(){
    strtype s("segul");
    char * p = new char[80];
    p = getString(&s);
    cout << p;
    return 0;
}