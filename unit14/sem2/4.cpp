#include <iostream>
#include <cstring>
using namespace std;
class output
{
	static char outbuf[255]; // this is the shared resource
		static int inuse;	 // better available if 0;
	static int oindex;		  // index of outbuf
	char str[80];
	int i;   // index of next char in str
	int who; // identifies the object , must be > 0
public:
	output(int w, const char *s)
	{
		strcpy(str, s);
		i = 0;
		who = w;
	}
	/* This function returns -1 if waiting for buffer,
	it returns 0 if it is done outputting, and it returns who if it is still using the buffer */
	int putbuf()
	{
		if (!str[i])
		{			   // done outputting	I
			inuse = 0; // release buffer	Sj
			return 0;  // signal termination	^
		}
		if (!inuse){
			//cout << "Using " << who << endl;
			inuse = who; // get buffer	M
		}
		if (inuse != who){
			cout << " Cannot use " << who << endl;
			//cout << "------------------------------------------------------" << endl;
			return -1; // in use by someone else
		}
		if (str[i])
		{ // still chars to output
			cout << "Using obj " << inuse << endl;
			outbuf[oindex] = str[i];
			i++;
			oindex++;
			outbuf[oindex] = '\0'; // always keep null - termir
			//cout << "------------------------------------------------------" << endl;
			return 1;
		}
		return 0;
	}
	void show() { cout << outbuf << '\n'; }
};
char output::outbuf[255]; // this is the shared resource
int output::inuse = 0;	// buffer available if 0
int output::oindex = 0;   // index of outbuf
int main()
{
	output obj1(1, "This is a test "), obj2(2, "of statics");
	while (obj1.putbuf() | obj2.putbuf())
	{

	}
	obj1.show(); // output chars
	return 0;
}