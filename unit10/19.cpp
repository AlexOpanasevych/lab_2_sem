#include <iostream>
#include <fstream>

using namespace std;

void copyToUpper(ifstream &fileIn, ofstream &fileOut){
    char ch;
    while(fileIn >> ch){
        if((ch < 'A' || ch > 'Z') && isalpha(ch)){
            ch-=32;
        }
        fileOut.put(ch);
    }
}

int main() {
    const string filename = "text1.txt";
    ofstream fileOut(filename);
    fileOut << "HeLoO WORld! TEst123";
    fileOut.close();
    ifstream file1(filename);
    ofstream file2("text2.txt");
    copyToUpper(file1, file2);

    return 0;
}