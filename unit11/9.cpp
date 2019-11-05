#include <iostream>
using namespace std;

class list {
public:
	list *head;
	list *tail;
	list *next;
	int num;
	list() {head = tail = next = NULL;}
	virtual void store(const int &i) = 0;
	virtual int retrieve() = 0;
};

class queue: public list {
public:
	void store(const int &i);
	int retrieve();
	queue operator+(const int &i) {store(i); return *this;} /*создание
													нового элемента*/
	int operator-(int ) {return retrieve();} //выталкивание
};

void queue::store(const int &i) {
	list *newItem;
	newItem = new queue;
	if(!newItem) {
		cout << "Allocation error.\n";
		exit(1);
	}
	newItem->num = i;
	if(tail) tail->next = newItem;
	tail = newItem;
	newItem->next = NULL;
	if(!head) head = tail;
}

int queue::retrieve() {
	int i;
	list *node;
	if(!head) {
		cout << "List empty.\n";
		return 0;
	}
	i = head->num;
	node = head;
	head = head->next;
	delete node;
	return i;
}

class stack: public list {
public:
	void store(const int &i);
	int retrieve();
	stack operator+(const int &i) {store(i); return *this;} /*создание
													нового элемента*/
	int operator-(int ) {return retrieve();} //выталкивание
};

void stack::store(const int &i) {
	list *newItem;
	newItem = new stack;
	if(!newItem) {
		cout << "Allocation error.\n";
		exit(1);
	}
	newItem->num = i;
	if(head) newItem->next = head;
	head = newItem;
	if(!tail) tail = head;
}

int stack::retrieve() {
	int i;
	list *temp;
	if(!head) {
		cout << "List empty.\n";
		return 0;
	}
	i = head->num;
	temp = head;
	head = head->next;
	delete temp;
	return i;
}

int main() {
	queue que;
	cout << "Queue: ";
	for (int i = 0; i < 10; i++)
	{
		que + i;
		cout << que - 0 << ' ';
	}
	cout << endl;
	stack stck;
	cout << "Stack: ";
	for (int i = 0; i < 10; i++)
	{
		stck + i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << stck - 0 << ' ';
	}
	return 0;
}