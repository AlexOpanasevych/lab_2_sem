#include <iostream>
using namespace std;

class samp {
 int a;
public:
    samp(int a = 0){this->a = a;};
    int get_a() { return a; }
};

int main() {
    samp obj(88); // init obj a to 88
    samp objarray[10]; // non - initialized 10-element array
    cout << obj.get_a() << endl;
    for(int i = 0; i < 10; i++){
        objarray[i].get_a();
    }
    return 0;
}