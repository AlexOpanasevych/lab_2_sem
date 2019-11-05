#include <iostream>
using namespace std;
class CountDown {
 int incr;
 int target;
 int current;
public:
 CountDown(int delay, int i=1) {
 target = delay;
 incr = i;
 current = 0;
 }
 bool counting () {
 current += incr;
 if (current >= target) {
 cout << "\a";
 return false;
 }
 cout << current << " ";
 return true;
 }
};
int main() {
 CountDown obj(100, 10);
 for (int i = 0; i < 10; i++)
 {
    obj.counting();
 }

 return 0;
}