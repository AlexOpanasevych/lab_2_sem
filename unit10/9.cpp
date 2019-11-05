#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int getWordCount(vector <char>& text){
    bool fFirstWord = true;
    int wordCount = 0;
    for(int i=0; i<text.size(); i++){
        if(text[i]==' '){
            if(fFirstWord){
                wordCount++;
                fFirstWord = false;
            }else {
                while (text[i]!=' ') i++;
                wordCount++;
            }

        }
    }
    return ++wordCount;
}

int main() {
    const char* filename = "test.txt";
    ofstream fileOut(filename);
    if(!fileOut.good() && !fileOut.eof()){
        cout << "Cannot create <" << filename << "> file." << endl;
        exit(1);
    }
    fileOut << "Here is a simple text that has 9 words";
    fileOut.close();

    ifstream fileInput(filename, ios::in | ios::binary);
    if(!fileInput.good() && !fileInput.eof()){
        cout << "Cannot create <" << filename << "> file." << endl;
        exit(1);
    }
    vector<char> buff;
    while(!fileInput.eof())
        buff.push_back(fileInput.get());
    cout << "File content: ";
    for(int i = 0; i<buff.size(); i++)
        cout << buff[i];
    cout << " - words counted: " << getWordCount(buff) << endl;

    return 0;
}