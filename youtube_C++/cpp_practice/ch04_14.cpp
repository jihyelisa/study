#include <iostream>
using namespace std;

int main()
{
	char s_string[100] = "C++ programming is very interesting!";
	char d_string[100];
	char d2_string[100];

	// ���ڿ� ����
	strcpy_s(d_string, 100, s_string);
	strncpy_s(d2_string, _countof(d2_string), s_string, 4);

	cout << "s_string: " << s_string << endl;
	cout << "d_string: " << d_string << endl;
	cout << "d2_string: " << d2_string << endl;

	// ���ڿ� ����
	strcat_s(d2_string, 100, s_string);
	cout << "d2_string: " << d2_string << endl;

	// ���ڿ� �� (�ƽ�Ű �ڵ� ������ ���� -1, 0, 1 (������ �ƽ�Ű�ڵ尡 �� ũ�� 1))
	cout << strcmp(d_string, d2_string) << endl;

	return 0;
}