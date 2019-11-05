#include <iostream>

using namespace std;

class DataStruct {
public:
	DataStruct *head;
	DataStruct *tail;
	DataStruct *next;
	int num;
	DataStruct() {head = tail = next = NULL;}
	virtual void store(const int &i) {
		DataStruct *newItem = new DataStruct;
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
	virtual int retrieve() {
		int i;
		DataStruct *node;
		if(!head) {
			cout << "DataStruct empty.\n";
			return 0;
		}
		i = head->num;
		node = head;
		head = head->next;
		delete node;
		return i;
	}
	virtual ~DataStruct(){};
	DataStruct operator+(const int &i) {store(i); return *this;} /*создание
													нового элемента*/
	int operator-(int ) {return retrieve();} //выталкивание
};

class queue: public DataStruct {
public:
	void store(const int &i);
	int retrieve();
	queue operator+(const int &i) {store(i); return *this;} /*создание
													нового элемента*/
	int operator-(int ) {return retrieve();} //выталкивание
};

void queue::store(const int &i) {
	DataStruct *newItem;
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
	DataStruct *node;
	if(!head) {
		cout << "DataStruct empty.\n";
		return 0;
	}
	i = head->num;
	node = head;
	head = head->next;
	delete node;
	return i;
}

class stack: public DataStruct {
public:
	void store(const int &i);
	int retrieve();
	stack operator+(const int &i) {store(i); return *this;} /*создание
													нового элемента*/
	int operator-(int ) {return retrieve();} //выталкивание
};

void stack::store(const int &i) {
	DataStruct *newItem;
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
	DataStruct *temp;
	if(!head) {
		cout << "DataStruct empty.\n";
		return 0;
	}
	i = head->num;
	temp = head;
	head = head->next;
	delete temp;
	return i;
}

DataStruct * DataStructFactory(char what){
	if(what == 's'){
		cout << "You chosed stack" << endl;
		return new stack;
	}
	if (what == 'q')
	{
		cout << "You chosed queue" << endl;
		return new queue;
	}
	cout << "You chosed nothing" << endl;
	return nullptr;
}

int main() {
	DataStruct * p;
	cout << "Queue or stack? ";
	char ch;
	cin.get(ch);
	p = DataStructFactory(ch);
	if (!p)
	{
		exit(1);
	}
	for (int i = 0; i < 10; i++)
	{
		*p + i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << (*p - 0) << ' ';
	}
	return 0;
}