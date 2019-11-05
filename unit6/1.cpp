#include <iostream>
#include <cstring>

using namespace std;

class strtype {
    char *p;
    int len;
public:
    strtype();
    strtype(const char *string, int len);
    ~strtype();
    char *getstring() { return p; }
    int getlength() { return len; }
};

strtype::strtype(){
    p = new char[255];
    p = 0;
    len = 255;
}

strtype::strtype(const char *string, int len){
    this->len = strlen(string);
    if(this->len >= len) {
        cout << "Failed to alloc\n";
        exit(1);
    }
    p = new char[len];
    strcpy(p, string);
    this->len = len;
}

strtype::~strtype(){
    delete [] p;
}

int main(){
    cout << "First constructor\n";
    strtype * str1 = new strtype();
    //cout << str1->getstring() << ' ' << str1->getlength()<< endl;
    strtype * str3 = new strtype("Second: Correct work", 25);
    cout << str3->getstring() << ' ' << str3->getlength() << endl;
    strtype * str2 = new strtype("Third: len 2", 1);
    return 0;
}
