#include <iostream>
using namespace std;

int main()
{
	int a = 100;
	int* pa;
	
	pa = &a; // pa�� a�� �ּҰ� �Ҵ�

	cout << "a�� ����� ��: " << a << endl; // a �Ϲݺ����� ��� ��
	cout << "a�� �ּ�: " << &a << endl; // &a �Ϲݺ����� �ּҰ�

	cout << "a�� ����� ��: " << *pa << endl; // *pa �����ͺ����� ��� �ּҰ� ����Ű�� ��
	cout << "a�� �ּ�: " << pa << endl; // pa �����ͺ����� ��� �ּҰ�

	a = 999;
	cout << "a�� ����� ��: " << *pa << endl; // 999
	cout << "a�� �ּ�: " << pa << endl; // a�� �ּҰ��� ������ ����

	return 0;
}