#include "ch09_01_student.h"

int main()
{
	Student p1; // ��ü ���� �� �����ڵ� �Բ� ȣ���
	// �����ڿ��� ���� �� �ʱ�ȭ
	// �ʱ�ȭ ���� ������? - Garbage Value�� ��µ�

	p1.ShowScore();

	cout << "*****************" << endl;

	p1.setScore(99, 93, 89);
	p1.SumAverage();
	p1.ShowScore();

	return 0;
}