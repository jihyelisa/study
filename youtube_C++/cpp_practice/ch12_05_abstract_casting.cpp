#include "ch12_05_geometric.h"

int main()
{
	Isosceles tri(4.2, 5.4);

	cout << "�ﰢ�� �غ�: " << tri.GetLine1() << endl;
	cout << "�ﰢ�� ����: " << tri.GetLine2() << endl;
	cout << "����: " << tri.AreaCalculation() << endl;
	cout << "�: " << tri.Compute() << endl;

	// �������� �������� �Ļ� ����
	Rectangle rect(1, 2);
	

	GeometricObject* p1 = new Isosceles(9, 15); // �Ļ�Ŭ���� ��ü�� ���Ŭ������ �� ĳ���� (�ڵ����� ����ȯ ��)
	Isosceles* p2 = new Isosceles(5, 6);
	cout << "p1: " << p1->GetLine1() << endl;
	cout << "p2: " << p2->GetLine1() << endl;


	Isosceles p3(9, 15);
	Rectangle p4(3, 7);

	DisplayGeometricObject(p3); // �ٿ� ĳ������ ���� �Լ�
	DisplayGeometricObject(p4);

	return 0;
};