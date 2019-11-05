#include <iostream>
using namespace std;

namespace st
{
	template <typename T>class Stack
	{
		T *array;
		int len;
	public:
		Stack()
		{
			array = new T[256];
			len = 0;
		}
		Stack(int size)
		{
			array = new T[size];
			len = 0;
		}
		void push(T value) 
		{
			array[len++] = value;
		}
		const T pop()
		{
			return array[--len];
		};
	};

	class COORD{
		int x; int y;
		public:
		COORD(int _x, int _y) : x(_x), y(_y) {}
		int getx() const{return this->x;}
		int gety() const{return this->y;}
	};
};
using namespace st;
int main()
{
	Stack<char> stck(20);
	for (int i = 0; i < 20; i++)
	{
		stck.push((char)(i+65));
	}
	for (int i = 0; i < 20; i++)
	{
		cout << stck.pop() << ' ';
	}
	COORD c(1, 2);
	cout << endl << c.getx() << ' ' << c.gety();
	return 0;
}