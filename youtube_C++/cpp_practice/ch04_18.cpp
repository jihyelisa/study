#include <iostream>
using namespace std;

int main()
{
	// ���۷��� ����
	// �̹� ������ ������ �߰��� �̸��� �ο��ϴ� ��

	int a = 100;
	int& ra = a;

	ra = 200;

	cout << "a = " << a << endl; //200
	cout << "ra = " << ra << endl; //200

	cout << "&a = " << &a << endl;
	cout << "&ra = " << &ra << endl; // ���� ������ �ּҰ�

	return 0;
}