#include "ch09_01_student.h"

int main()
{
	Student p1; // ��ü ���� �� �����ڵ� �Բ� ȣ���
	// �����ڿ��� ���� �� �ʱ�ȭ
	// �ʱ�ȭ ���� ������? - Garbage Value�� ��µ�

	p1.ShowScore();

	p1.setScore(99, 93, 89);
	p1.SumAverage();
	p1.ShowScore();

	Student p2(90, 98, 76); // �Ķ���Ͱ� �ִ� ������ ȣ��
	p2.SumAverage();
	p2.ShowScore();

	Student p3(p1); // ���� ������, copy contructure
	// ��ü�� �Ķ���ͷ� ������
	// ��, ���� �����ڴ� �����Ϸ��� �ռ����ִ� �������̹Ƿ� �Ķ���Ϳ� ���Ե��� ���� sum, average ���� �ʱ�ȭx
	p3.SumAverage();
	p3.ShowScore();

	Student* p4; // ������ ��ü, pointer to object
	// �� �ʱ�ȭ �� ��
	// ��ü�� �ƴϰ� �������̱� ������ �Ҹ��� ȣ��x
	p4 = &p2;
	p4->ShowScore();

	Student* p5 = new Student(86, 75, 90); // �����Ҵ�
	p5->SumAverage();
	p5->ShowScore();
	delete(p5); // �Ҹ��� ȣ���

	Student& p6 = p1; // ���� ��ü
	p6.ShowScore();

	return 0;
}