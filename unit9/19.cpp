#include <iostream>
#include <cmath>
using namespace std;

#define SIZE 10

class stack {
 char stck[SIZE]; // holds the stack
 int tos; // index of top -of - stack
public:
 stack();
 void push(char ch); // push character on stack
 char pop(); // pop character from stack
 friend ostream & operator <<(ostream & stream, stack & s){for(int i = s.tos - 1; i >= 0; i--) stream << s.stck[i] << ' '; return stream;}
};
// Initialize the stack:
stack::stack() {
 tos = 0;
}
// Push a character
void stack::push (char ch) {
 if (tos == SIZE) {
 cout << "Stack is full\n";
    return;
 }
 stck[tos] = ch;
 tos++;
}
// Pop a character:
char stack::pop() {
 if (tos==0) {
 cout << "Stack is empty\n";
 return 0;
 }
 tos--;
 return stck[tos];
}


int main(){
    stack s;
    for(int i = 0; i < 10; i++)
        s.push((char)(i+65));
    cout << s;
    return 0;
}