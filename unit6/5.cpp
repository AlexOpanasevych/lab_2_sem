#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

long mystrtol(char *p, char **end){
    return strtol(p, end, 10);
}

int main() {
    char * p = new char[10];
    char *end;
    cin.getline(p, 10);
    cout << mystrtol(p, &end);
    return 0;
}