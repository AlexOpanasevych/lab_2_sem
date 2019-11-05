#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class strtype
{
    char *p;
    int len;

  public:
    strtype(){
        p = new char[256];
        if(!p) exit(1);
    }
    strtype(const char *ptr);
    ~strtype() { delete[] p; }
    friend ostream &operator<<(ostream &stream, strtype &obj);
    friend istream &operator>>(istream &stream, strtype &obj);
};
strtype::strtype(const char *ptr)
{
    len = strlen(ptr) + 1;
    p = new char(len);
    if (!p)
    {
        cout << "Allocation error\n";
        exit(1);
    }
    strcpy(p, ptr);
}

ostream & operator << (ostream &stream, strtype &obj){
    return stream << obj.p;
}

istream & operator >> (istream &stream, strtype &obj){
    return stream >> obj.p;
}

int main()
{
    strtype s1, s2;
    cin >> s1 >> s2;
    cout << s1 << '\n' << s2;
    return 0;
}