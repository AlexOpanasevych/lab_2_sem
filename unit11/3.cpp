#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void SplitToVector(vector<string> &v, string dlm, string src){
    string::size_type p, start=0, len=src.length(); 
    v.clear();
    start = src.find_first_not_of(dlm);
    p = src.find_first_of(dlm, start);
    while(p != string::npos){
        v.push_back(src.substr(start, p-start));
        start = src.find_first_not_of(dlm, p);
        p = src.find_first_of(dlm, start);
    }
    if(len>start)//rest
        v.push_back(src.substr(start, len - start));
}


void countWords(char * word){
	vector<string> words;
	string line;
	ifstream in("3.txt");
	getline(in, line);
	string temp = word;
	SplitToVector(words, " ,./?!@#$)(*&^%", line);
    cout << "Word that is repeated in file: " << endl;
    int k = 0;
    for (unsigned int j = 0; j < words.size(); j++)
    {
		if (words[j] == temp)
			k++;
    }
	if (k >= 1)
        cout << word << ' ' << k << endl;
}

void countWords1(){
	vector<string> words;
	string line;
	ifstream in("1.txt");
	getline(in, line);
	SplitToVector(words, " ,./?!@#$", line);
    printf("Words that are repeated in file:\n");
    int k;
    for (unsigned int j = 0; j < words.size(); j++)
    {
        k = 0;
        for (unsigned int i = j + 1; i < words.size(); i++)
        {
            if (words[j] == words[i])
            {
                while (words[j] == words[i]){
                    words.erase(words.begin() + i);
                    k++;
                }
            }
        }
        k++;
        if (k > 1)
            cout << words[j] << ' ' << k << endl;
    }
}




int main(int argc, char * argv[]){
	countWords(argv[1]);
	return 0;
}