#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void createFilesForTasks(){
    string path;
    cout << "Input path:";
    getline(cin, path);
    for (size_t i = 0; i < path.length(); i++)
    {
        if (path[i] == '\\')
        {
            path[i] = '/';
        }
    }
    path.append("/");
    cout << path << endl;
    int count;
    cout << "Input count of files: ";
    cin >> count;
    //string nameFile;
    for (int i = 1; i <= count; i++)
    {
        ofstream currFile(path + to_string(i) + ".cpp");
        if(currFile.fail()) cout << "ERROR" << endl;
        currFile << "#include <iostream>" << endl
        << "#include <fstream>" << endl
        << "#include <string>" << endl
        << "#include <vector>" << endl
        << "using namespace std;" << endl
        << "int main(){" << endl
        << '\t' << "return 0;" << endl << '}';
        currFile.close();
    }
}

int main(){
    createFilesForTasks();
    system("pause");
    return 0;
}