#include "ch11_02_str.h"

int main()
{
	StringCharArray one;
	char t_str[50];

	one.assign("sample"); // 상속 받은 클래스 string의 함수에 접근 가능
	one.toCharArray(t_str);

	cout << one << endl;
	cout << t_str << endl;
	
	return 0;
};