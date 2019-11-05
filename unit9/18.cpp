#include <iostream>
#include <cmath>
using namespace std;

class box{
    int size;
    public:
    box(int size){this->size = size;}
        void show(){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    if(i==0 || i==size - 1 || j==0 || j== size - 1)
                    {   
                        cout << '*';
                    }
                    else
                    {
                        cout << ' ';
                    }
                }
                cout << endl;
            }
            cout << endl;
        }
};

int main(){
    box b(5);
    b.show();
    return 0;
}