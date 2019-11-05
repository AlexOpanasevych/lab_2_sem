#include <iostream>
#include <fstream>
#include <iomanip>
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cout << " Usage : CONVERT <input> <output>\n";
		return 1;
	}
	std::ifstream fin(argv[1]);
	std::ofstream fout(argv[2]);
	if (!fout)
	{
		std::cout << "Cannot open output file.\n";
		return 1;
	}
	if (!fin)
	{
		std::cout << "Cannot open input file.\n";
		return 1;
	}
	char ch;
	fin.unsetf(std::ios::skipws); // do not skip spaces
	while (!fin.eof())
	{
		fin >> ch;
		if (ch == ' ')
			ch = '|';
		if (!fin.eof())
			fout << ch;
	}
	fin.close();
	fout.close();
	return 0;
}