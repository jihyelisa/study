#include <iostream>
using namespace std;

int main()
{
	char s_string[100] = "C++ programming is very interesting!";
	char d_string[100];
	char d2_string[100];

	// 문자열 복사
	strcpy_s(d_string, 100, s_string);
	strncpy_s(d2_string, _countof(d2_string), s_string, 4);

	cout << "s_string: " << s_string << endl;
	cout << "d_string: " << d_string << endl;
	cout << "d2_string: " << d2_string << endl;

	// 문자열 결합
	strcat_s(d2_string, 100, s_string);
	cout << "d2_string: " << d2_string << endl;

	// 문자열 비교 (아스키 코드 순서에 따라 -1, 0, 1 (왼쪽의 아스키코드가 더 크면 1))
	cout << strcmp(d_string, d2_string) << endl;

	return 0;
}