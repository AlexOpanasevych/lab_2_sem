#include <iostream>
#include <cstring>

using namespace std;

class strtype{
    char *ptr;
    int len;
    public:
    strtype(char const *s);
    ~strtype(){
        cout << "Freeing ptr..." << endl;
        delete [] ptr;
    }
    char * get() {return ptr;}
    strtype & operator = (const strtype & obj);
    char & operator [](int i);
    strtype(const strtype & s);
};

char & strtype::operator [](int i){
    //cout << '1' << ' ';
    if(i < 0 || i >= len) {
        exit(1);
    }
    return ptr[i];
}

strtype::strtype(char const *s){
    int len = strlen(s) + 1;
    ptr = new char[len];
    if(!ptr) {
        cout << "Alloc err" << endl;
        exit(1);
    }
    this->len = len;
    strcpy(ptr, s);
}

strtype::strtype(const strtype & s){
    this->len = s.len;
    ptr = new char[this->len];
    if(!ptr) exit(1);
    strcpy(ptr, s.ptr);
}

strtype & strtype:: operator = (const strtype & obj){
    if(len < obj.len){
        delete [] ptr;
        ptr = new char[obj.len];
        if(!ptr) exit(1);
    }
    len = obj.len;
    strcpy(ptr, obj.ptr);
    return *this;
}

int main(){
    strtype a("Hello"), b("Goodbye");
    cout << a.get() << endl;
    a = b;
    strtype c(a); // is better when we want to build a copy of object, not equate them
    for(int i = 0; i < (int)strlen(c.get()); i++){
        cout << c[i] << ' ';
    }
    cout << endl;
    return 0;
}