#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream output; //출력 파일 객체 생성
	char cont = 'y';
	char word[50] = { 0, };

	output.open("test.txt"); //출력 파일 열기

	if (output.fail())
		return 1;

	while (cont == 'y' || cont == 'Y')
	{
		cout << "단어 입력: ";
		cin >> word; //표준 입력 장치 - 키보드로 자료 입력

		output << word << endl; // 출력 파일에 내용 출력

		cout << "계속하시겠습니까? (y/n) ";
		cin >> cont;
	}

	output.close(); //파일 닫기

	return 0;
}