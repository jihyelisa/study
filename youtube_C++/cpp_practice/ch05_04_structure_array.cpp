#include "config.h"

int main()
{
	SAM arr[5] = {
		"�̸�1", "010-0000-0000",
		"�̸�2", "010-0000-0000",
		"�̸�3", "010-0000-0000",
		"�̸�4", "010-0000-0000",
		"�̸�5", "010-0000-0000",
	};

	cout << "�迭 ��� �ϳ��� ũ��: " << sizeof(SAM) << endl;

	for (int i = 0; i < 5; i++)
		cout << "arr[" << i << "]�� �ּ�: " << &arr[i] << endl;

	for (int i = 0; i < 5; i++)
		cout << "�̸�: " << arr[i].Name << "\t��ȣ: " << arr[i].MPhoneNum << endl;

	// ����ü �迭 �ּҰ�
	SAM* ps = &arr[2];
	cout << (*ps).Name << endl;
	cout << ps->Name << endl;

	return 0;
}