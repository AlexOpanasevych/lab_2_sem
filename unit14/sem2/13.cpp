#include <iostream>
#include <vector>
using namespace std;


string name;
//vector <string> names(100);

int main(){
	// одна з найкращих переваг - це економія часу та пам'яті при компіляції, оскільки компілятор використовує тільки ті функції, 
	// які йому потрібні, без потреби завантаження додаткових даних
	cin >> name;
	cout << name;
	/*for (auto i : names)
	{
		cin >> i;
		cout << i << endl;
	}*/
	
	return 0;
}

namespace std{
	#include <string>
}