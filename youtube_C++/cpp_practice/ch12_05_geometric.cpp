#include "ch12_05_geometric.h"

GeometricObject::GeometricObject()
{
	line1 = 0;
	line2 = 0;
}

GeometricObject::GeometricObject(const double line1, const double line2)
{
	this->line1 = line1;
	this->line2 = line2;
}

void GeometricObject::SetLine1(const double line1)
{
	this->line1 = line1;
}

void GeometricObject::SetLine2(const double line2)
{
	this->line2 = line2;
}

double GeometricObject::GetLine1()
{
	return line1;
}

double GeometricObject::GetLine2()
{
	return line2;
}



Isosceles::Isosceles()
	:GeometricObject()
{
	side = 0;
	area = 0;
}

Isosceles::Isosceles(const double base, const double height)
	:GeometricObject(base, height) // ���Ŭ������ ������ ȣ���Ͽ� line1, 2 �ʱ�ȭ
{
	// ������ ������ 0���� �ʱ�ȭ
	side = 0;
	area = 0;
}

double Isosceles::AreaCalculation()
{
	area = line1 * line2 * 0.5;
	return area;
}

double Isosceles::Compute()
{
	side = sqrt((line1 / 2) * (line1 / 2) + line2 * line2); // �̵�ﰢ�� � ���
	return side;
}

double Isosceles::GetSide()
{
	return side;
}

double Isosceles::GetArea()
{
	return area;
}

Rectangle::Rectangle(const double base, const double height)
	:GeometricObject(base, height) // ���Ŭ������ ������ ȣ���Ͽ� line1, 2 �ʱ�ȭ
{}

double Rectangle::Compute()
{
	return 0;
}

double Rectangle::AreaCalculation()
{
	return 0;
}



// ���Ŭ���� ��ü�� �Ļ�Ŭ������ �ٿ� ĳ����
void DisplayGeometricObject(GeometricObject& object) // ���� �Ļ�Ŭ������ �Ķ���ͷ� ���� �� ����
{
	cout << "line1: " << object.GetLine1() << endl;
	cout << "line2: " << object.GetLine2() << endl;

	GeometricObject* p = &object;
	Isosceles* p1 = dynamic_cast<Isosceles*>(p); // �ٿ� ĳ����
	Rectangle* p2 = dynamic_cast<Rectangle*>(p); // �ٸ� �Ļ�Ŭ�����ε� ���ÿ� �ٿ� ĳ���� ����

	if (p1 != NULL) // ó�� �Ķ���ͷ� ���� ��ü�� Isosceles�� �ƴ϶�� p1�� NULL���� ��
	{
		p1->AreaCalculation();
		p1->Compute();

		cout << "�̵�ﰢ���� ����: " << p1->GetArea() << endl;
		cout << "�̵�ﰢ���� �: " << p1->GetSide() << endl;
	}

	if (p2 != NULL)
	{
		cout << "p2 != NULL" << endl;
	}
}