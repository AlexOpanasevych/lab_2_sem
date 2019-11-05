#include <iostream>
#include <ctime>
#include <Windows.h>
#define MILSEC_PER_SEC 1000
using namespace std;

class StpWtch{
    clock_t startProgram;
    clock_t endOfTimer;
    clock_t startTimer;
    clock_t endOfProgram;
    public:
        int seconds;
        StpWtch();
        StpWtch(time_t time){
            startProgram = time;
        }
        ~StpWtch();
        void start();
        void stop();
        void show();
};

StpWtch::StpWtch(){
    startProgram = clock();
}

void StpWtch::start(){
    cout << "Started"<< endl;
    startTimer = clock();
}

void StpWtch::stop(){
    cout << "Timer stopped!";
    endOfTimer = clock();
}

void StpWtch::show(){
    cout << "Time : " << (double)(clock() - startTimer)/(double)CLOCKS_PER_SEC << endl;
}

StpWtch::~StpWtch(){
    endOfProgram = clock();
    cout << "Elapsed time : " << (double)(endOfProgram - startProgram)/(double)CLOCKS_PER_SEC << endl;
}

int main(){
    StpWtch timer(clock());
    cout << "Input time: ";
    cin >> timer.seconds;
    timer.start();
    Sleep(timer.seconds*MILSEC_PER_SEC);
    timer.stop();
    timer.show();
    return 0;
}