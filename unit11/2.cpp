#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool fileCopy(string nameFile){
	string copyString;
	string temp;
	ifstream in(nameFile);
	if(!in.good()) return false;
	while (!in.eof())
	{
		temp.clear();
		getline(in, temp);
		for (unsigned int i = 0; i < temp.length(); i++){
			if (temp[i] == '\t')
			{
				copyString.append("    ");
			}
			
			copyString.push_back(temp[i]);
		}
		
		cout << copyString << endl;
	}
	in.close();
	ofstream out("copy" + nameFile);
	out << copyString;
	out.close();
	return true;
}

int main(){
	fileCopy("1.txt");
	return 0;
}