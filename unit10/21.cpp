#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#define SIZE 40
class inventory {
	char item[SIZE]; // name of item
	int onhand; // number on hand
	double cost; // cost of item
public:
	inventory(const char *i, int o, double c) {
		strcpy(item, i);
		onhand = o;
		cost = c;
	}
	void store(fstream &stream);
	void retrieve(fstream &stream);
	friend ostream &operator <<(ostream &stream, inventory obj);
	friend istream &operator >>(istream &stream, inventory &obj);
};
ostream &operator <<(ostream &stream, inventory obj) {
	stream << obj.item << ": " << obj.onhand;
	stream << " on hand at $" << obj.cost << '\n';
	return stream;
}
istream &operator >>(istream &stream, inventory &obj) {
	cout << "Enter item name: ";
	stream >> obj.item;
	cout << "Enter number on hand: ";
	stream >> obj.onhand;
	cout << " Enter cost: ";
	return stream >> obj.cost;
}

void inventory::store(fstream &stream) {
	stream << item << ' ' << onhand;
	stream << ' ' << cost << "\r\n";

}
void inventory::retrieve(fstream &stream) {
	stream >> item;
	stream >> onhand;	
	stream >> cost;
}

int main(){
	inventory a("Books", 2 , 35), b("", 0, 0);
	cout<<"Enter second item. "<<endl;
	cin>>b;
	fstream f("inventory.txt", ios::out | ios::binary);
	if(!f) {
		cout << "Cannot open a file!";
		return 1;
	}
	a.store(f);
	b.store(f);
	cout << a << b;
	f.close();
	f.open("inventory.txt", ios::in | ios::binary);
	inventory c("", 0, 0);
	c.retrieve(f);
	cout << c;
	f.close();
	return 0;
}