#include <iostream>
#pragma warning (disable: 4290)
using namespace std;

// �Լ� �ȿ��� ����� ���� �Լ� ���� �� throw ������ֱ�
//void ThrowFunc(const int n) throw (int);

// try �ȿ��� ȣ���� ��� �Լ� ���� throw�� ����ó���� ��� ����
//void ThrowFunc(const int n) throw (int)
//{
//	if (n == 0)
//		throw n;
//}

int main()
{
	int number1, number2;
	int quotient, reminder;

	cout << "��1: ";
	cin >> number1;
	cout << "��2: ";
	cin >> number2;

	try
	{
		if (number2 == 0)
			throw number1; // ����ó�� // number1 ���� ������ catch�� ��

		quotient = number1 / number2;
		reminder = number1 % number2;

		cout << "��: " << quotient << endl;
		cout << "������: " << reminder << endl;
	}
	catch (int e_num)
	{
		cout << e_num << "�� 0���� ���� �� �����ϴ�." << endl;
	}
}