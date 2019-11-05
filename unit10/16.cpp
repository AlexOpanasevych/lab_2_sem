#include <iostream>
#include <fstream>

using namespace std;

void swapSymbFileBuff(fstream &file){
    file.seekg(0, ios::end);
    int fileSize = file.tellg();
    file.seekp(0, ios::beg);
    file.seekg(0, ios::beg);
    char buff[fileSize];
    for(int i = 0; i < fileSize - 1; i++){
        if(i%2){
            ++i;
        }
        buff[i+1] = file.get();
        buff[i] = file.get();
    }
    cout << buff << endl;
    file.seekp(0, ios::beg);
    file << buff;
}

int main() {
    const string filename = "test.txt";
    ofstream fileOut(filename);
    fileOut << "This is a simple text!";
    fileOut.close();
    fstream file(filename);
    //cout << "First swap: ";
    swapSymbFileBuff(file);

    file.close();


    return 0;
}