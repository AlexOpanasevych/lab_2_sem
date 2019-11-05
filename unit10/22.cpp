#include <iostream>
//#include <string>
#include <fstream>
using namespace std;

const int SIZE = 20;

class stack{
    ifstream stckIn;
    ofstream stckOut;
    int size;
    public:
    stack(){
        
        
        size = 0;
    }
    void stInOpen(){stckIn.open("1.txt", ios::in | ios::binary);}
    void stOutOpen(){stckOut.open("1.txt", ios::out | ios::binary);}
    void stOutClose(){stckOut.close();}
    void stInClose(){stckIn.close();}
    char pop(){
        //ifstream stckIn("1.txt");
        //cout << size;
        stckIn.seekg(size - 1, ios::beg);
        char temp;
        stckIn.get(temp);
        size--;
        //stckIn.close();
        return temp;
    }
    void push(char _Elem){
        //cout << _Elem;
        //ofstream stckOut("1.txt");
        stckOut.seekp(size, ios::beg);
        stckOut.put(_Elem);
        size++;
        //stckOut.close();
    }
};

int main(){
    stack s;
    s.stOutOpen();
    for (int i = 0; i < 26; i++)
    {
        s.push((char)(65+i));
    }
    s.stOutClose();
    s.stInOpen();
    for (int i = 0; i < 26; i++)
    {
        cout << s.pop() << ' ';
    }
    s.stInClose();
    
}