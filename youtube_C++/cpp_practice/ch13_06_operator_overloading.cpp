#include "ch13_06_time.h"

int main()
{
	Time t1(7, 30, 20);

	cout << t1.ShowTime() << endl;
	cout << "�ð� - �ʴ���: " << t1.CalSec() << endl;

	Time t2(4, 50, 23);

	if (t1 <= t2)
		cout << t1.ShowTime() << "�� " << t2.ShowTime() << "���� �۰ų� ����." << endl;
	else
		cout << t1.ShowTime() << "�� " << t2.ShowTime() << "���� ũ��." << endl;
}