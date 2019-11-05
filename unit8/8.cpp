#include <iostream>
using namespace std;
class A
{
    int i;
  public:
    A(int a) {cout << "Constructing A..." << endl; i = a; }
};
class B
{
    int j;
  public:
    B(int a) {cout << "Constructing B..." << endl; j = a; }
};
class C : public A, public B
{
    int k;
  public:
    C(int i, int j, int k) : A(i), B(j){
        cout << "Constructing C..." << endl;
        this->k = k;
    }
};

int main(){
    C a(1, 2, 3);
    return 0;
}