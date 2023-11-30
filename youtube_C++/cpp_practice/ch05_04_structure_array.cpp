#include "config.h"

int main()
{
	SAM arr[5] = {
		"이름1", "010-0000-0000",
		"이름2", "010-0000-0000",
		"이름3", "010-0000-0000",
		"이름4", "010-0000-0000",
		"이름5", "010-0000-0000",
	};

	cout << "배열 요소 하나의 크기: " << sizeof(SAM) << endl;

	for (int i = 0; i < 5; i++)
		cout << "arr[" << i << "]의 주소: " << &arr[i] << endl;

	for (int i = 0; i < 5; i++)
		cout << "이름: " << arr[i].Name << "\t번호: " << arr[i].MPhoneNum << endl;

	// 구조체 배열 주소값
	SAM* ps = &arr[2];
	cout << (*ps).Name << endl;
	cout << ps->Name << endl;

	return 0;
}