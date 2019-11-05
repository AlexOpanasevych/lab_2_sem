#include <iostream>
#include <iomanip>
using namespace std;

class ft_to_cms
{
    double feet;
    double cms;
  public:
    void set()
    {
        cms = feet * 30.48;
    }
    friend istream & operator >>(istream & stream, ft_to_cms & f) {
        cout << "INPUT FEETS PLEASE : ";
        return stream >> f.feet;
    }
    friend ostream & operator <<(ostream & stream, ft_to_cms & f){
        return stream << "Feets : " << f.feet << endl << "Cms : " << f.cms;
    }
};

int main(){
    ft_to_cms a;
    cin >> a;
    a.set();
    cout << a;
    return 0;
}