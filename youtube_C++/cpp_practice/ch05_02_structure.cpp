#include <iostream>
#include <string>
using namespace std;

int main()
{
	struct SAM // ����ü �±�
	{
		char Name[30]; //����ü ���
		char MPhoneNum[20];
	};
	
	// struct SAM Friend, Friend1;
	SAM Friend, Friend1; // struct ���� ����

	strcpy_s(Friend.Name, 30, "�谩��");
	strcpy_s(Friend.MPhoneNum, 20, "010-1234-5678");

	cout << Friend.Name << endl;
	cout << Friend.MPhoneNum << endl;

	Friend1 = Friend; // ����ü ������ ���� �� ����

	cout << Friend1.Name << endl;
	cout << Friend1.MPhoneNum << endl;

	// ����ü ����� �ٸ� ����ü�� ���� ���� ����

	return 0;
}