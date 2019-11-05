/* ----------------------------------------------------------------<Header>-
 Name: 7.cpp
 Title:  Задача 2 .7.
 Group: TI-81
 Student: Opanasevych O.B.
 Written: 2019-02-22
 Revised: 
 Description: Объясните, почему работает такой код:
#include <cstdlib>
#include <iostream>
using namespace std;
int main (int argc, char **argv){
 cout << argv[argc-1] << endl
 << argc[argv-1] << endl;
 return EXIT_SUCCESS;
}
 ------------------------------------------------------------------</Header>-*/

#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char **argv){
    cout << argv[argc-1] << endl << argc[argv-1] << endl;
    cout << "argc = " << argc << endl;
    cout << "sizeof argv = " << sizeof(argv) << endl;
    cout << "sizeof argc = " << sizeof(argc) << endl;
    cout << "sizeof argv[argc-1] = " << sizeof(argv[argc-1]) << endl;
    cout << "sizeof argc[argv-1] = " << sizeof(argc[argv-1]) << endl;
    cout << "argv[argc-1] = " << argv[argc-1] << endl; 
    cout << "argc[argv-1] = " << argc[argv-1] << endl;
    return EXIT_SUCCESS;
}

// этот код работает потому что адреса argv[argc-1] и argc[argv-1] совпадают, и их размеры одинаковые