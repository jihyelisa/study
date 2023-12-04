#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream input; //涝仿 颇老 按眉 积己
	char word[50] = { 0, };

	input.open("test.txt");
	if (input.fail())
		return 1;

	while (input.eof() == false)
	{
		input >> word;
		cout << word << endl;
	}

	input.close();

	return 0;
}