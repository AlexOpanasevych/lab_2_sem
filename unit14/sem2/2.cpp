#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

class strtype
{
	char str[80];
	int len;

public:
	strtype(const char *s)
	{
		strcpy(str, s);
		len = strlen(s);
	}
	operator char *() { return str; }
	operator int()
	{
		int sign = 1, base = 0, i = 0;
		// if whitespaces then ignore.
		while (str[i] == ' ')
		{
			i++;
		}
		// sign of number
		if (str[i] == '-' || str[i] == '+')
		{
			sign = 1 - 2 * (str[i++] == '-');
		}
		// checking for valid input
		while (str[i] >= '0' && str[i] <= '9')
		{
			// handling overflow test case
			if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7))
			{
				if (sign == 1)
					return INT_MAX;
				else
					return INT_MIN;
			}
			base = 10 * base + (str[i++] - '0');
		}
		cout << "Number - " << base * sign << endl;
		return (int)strlen(str);
	}
};

int myAtoiRecursive(char *str, int n) 
{ 
    // Base case (Only one digit) 
    if (n == 1) 
        return *str - '0'; 
  
    // If more than 1 digits, recur for (n-1), multiplu result with 10 
    // and add last digit 
    return (10 * myAtoiRecursive(str, n - 1) + str[n-1] - '0'); 
} 

int main()
{
	strtype s("200");
	char *p, s2[80];
	p = s;
	cout << "Here is string: " << p << '\n';
	strcpy(s2, s);
	cout << "Here is copy of string: " << s2 << '\n';
	cout << myAtoiRecursive(s, (int)strlen(s)) << endl;
	return 0;
}