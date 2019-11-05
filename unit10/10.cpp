#include <iostream>
#include <fstream>
#include <string>
#include <cstring> // for strcpy()
using namespace std;

inline void getFileString(){
    string nameFile;
    cout << "Input name of file: ";
    cin >> nameFile;
    ifstream in(nameFile);
    string str;
    getline(in, str);
    in.close();
    ofstream of("copy" + nameFile);
    cout << str.length() << " " << str << endl;
    of << str;
    of.close();
    //delete temp;
    cout << "Done" << endl;
}

int countOfWords(){
    string nameFile;
    cin >> nameFile;
    ifstream in(nameFile);
    string str;
    int count = 1;
    while (!in.eof()){
        getline(in, str);
        for (unsigned int i = 0; i < str.length(); i++)
        {
            if(str[i] == ' ') count++;
        }
    }
    
    return count;
    
}

int main(){
    getFileString();
    cout << countOfWords();
    return 0;
}