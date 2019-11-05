#include <iostream>
#include <cstring>

using namespace std;

class strtype{
    char *str;
    public:
    strtype(const char* _str = "");
    //
    ~strtype(){cout << "deleting" << endl; delete [] str;}
    strtype& operator=(const strtype&);
    friend strtype operator+(const strtype&, const strtype&);
    friend bool operator>(const strtype&, const strtype&);
    friend bool operator==(const strtype&, const strtype&);
    friend bool operator<(const strtype&, const strtype&);
    strtype & operator+=(const strtype & rhs);
    void print(){cout << str << endl;}
};

strtype::strtype(const char* _str)
{
    str = new char[strlen(_str)+1];
    strcpy(str, _str);
}

strtype & strtype ::operator+=(const strtype & rhs)
{
    int sz = strlen(this->str) + strlen(rhs.str);
 
    char* ts = new char[sz+1];
 
    for (int i = 0; i < (int)strlen(this->str); i++)
        ts[i] = this->str[i];
    for (int ii = strlen(this->str), j = 0; ii <= sz; ii++, j++)
        ts[ii] = rhs.str[j];
 
    delete [] this->str;
    this->str = ts;
 
    return *this;
}

strtype& strtype::operator=(const strtype& rhs)
{
    if (this != &rhs)
    {
        delete[] this->str;
        this->str = new char[strlen(rhs.str)+1];
        strcpy(this->str, rhs.str);
    }
 
    return *this;
}

strtype operator+(const strtype& lhs, const strtype& rhs)
{
    strtype ts = lhs;
 
    return ts += rhs;
}

bool operator==(const strtype& lhs, const strtype& rhs)
{
    return !strcmp(lhs.str, rhs.str);
}

bool operator>(const strtype& lhs, const strtype& rhs)
{
    return (strlen(lhs.str) > strlen(rhs.str)) ? true : false;
}

bool operator<(const strtype& lhs, const strtype& rhs)
{
    return (strlen(lhs.str) < strlen(rhs.str)) ? true : false;
}

int main(){
    strtype a("I love ");
    strtype b("C++!");
    strtype c("C++!");
    b.print();
    c.print();
    if(b == c) cout << "b eq c" << endl; else cout << "NOT" << endl;
    if(a < c) cout << "a < c" << endl; else cout << "NOT" <<endl;
    if(a > c) cout << "a > c" << endl;
    strtype d = a + b;
    d.print();
    return 0;
}