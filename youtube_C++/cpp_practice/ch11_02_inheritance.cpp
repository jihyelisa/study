#include "ch11_02_str.h"

int main()
{
	StringCharArray one;
	char t_str[50];

	one.assign("sample"); // ��� ���� Ŭ���� string�� �Լ��� ���� ����
	one.toCharArray(t_str);

	cout << one << endl;
	cout << t_str << endl;
	
	return 0;
};