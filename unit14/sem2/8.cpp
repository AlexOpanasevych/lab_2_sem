#include <iostream>
using namespace std; 

class Simple {
    bool var;
public:
    Simple(bool _var) : var(_var){}
    operator bool() const { return var; }
};

class SimpleExplicit {
    bool var;
public:
    SimpleExplicit(){var = true;}
    SimpleExplicit(bool _var) : var(_var){}
    explicit operator bool() const { return var; }
};

int main(int, char**) {
    
    Simple s = false;
    bool b = s; // OK
    cout << b << endl;
    SimpleExplicit se = true;
    // bool a = se; // COMPILE ERROR
    bool c = static_cast<bool>(se); // OK
    cout << c << endl;
    // BUT...
    if(se) // OK - no need explicit cast to bool
    {
    };

    return 0;
}