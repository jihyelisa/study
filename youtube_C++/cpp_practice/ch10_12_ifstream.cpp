#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream input; //입력 파일 객체 생성
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