/* ----------------------------------------------------------------<Header>-
 Name: .cpp
 Title:  Задача 2.4.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description: 
 Создайте класс card, который поддерживает каталог библиотечных карточек. Этот
класс должен хранить заглавие книги, имя автора и выданное на руки число экземпляров книги.
Заглавие и имя автора храните в виде строки символов, а количество экземпляров - в виде
целого числа. Используйте открытую функцию-член store() для запоминания информации о
книгах и открытую функцию-член show() для вывода информации на экран. В функцию main()
включите краткую демонстрацию работы созданного класса.
 ------------------------------------------------------------------</Header>-*/

#include <iostream>
#include <cstring>
using namespace std;

class Card{
    private:
        char * head;
        char * authorName;
        int count;
    public:
        Card();
        ~Card();
        void store(char * aName, char * h, int count);
        void show();
};

Card::Card(){
    head = new char[80];
    authorName = new char[80];
}

Card::~Card(){
    delete[] head;
    delete[] authorName;
}

void Card::store(char * aName, char * h, int count){
    strcpy(head, h);
    strcpy(authorName, aName);
    this->count = count;
}

void Card::show(){
    cout << authorName << ' ' << head << ' '<< count;
}

int main(){
    Card* card = new Card();
    cout << "input author and press enter, input head and press enter ";
    char * a = new char[80], *b = new char[80]; int c;
    cin.getline(a, 80);
    cin.getline(b, 80);
    cout << "input count of this book: ";
    cin >> c;
    card->store(a, b, c);
    card->show();
    delete card;
    return 0;
}