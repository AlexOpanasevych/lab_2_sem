#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void readnCount(ifstream &file){
    string buff;
    struct alphabet{
        char symb;
        int count;
    };
    vector <struct alphabet> alphacount;
    for(int i = 0; file >> buff[i]; i++){
        if(i == 0) alphacount.push_back({buff[i], 1});
        else for(int j = 0; j< (int)alphacount.size(); j++){
            if(alphacount[j].symb == buff[i]) {
                alphacount[j].count++;
                break;
            }
            else if(alphacount[j].symb != buff[i] && j== (int)alphacount.size()-1) {
                alphacount.push_back({buff[i], 1});
                break;
            }
        }
    }
    cout << "Totally read: " << endl;
    for(int i=0; i < (int)alphacount.size(); i++)
        cout << "  " << alphacount[i].symb << " - " << alphacount[i].count << " symbols" << endl;
}

int main() {
    const string filename = "text.txt";
    ofstream fileOut(filename);
    fileOut << "Hello world!";
    fileOut.close();
    ifstream fileIn(filename);
    readnCount(fileIn);
    cout << "String: " << "Hello world!" << endl;
    return 0;
}