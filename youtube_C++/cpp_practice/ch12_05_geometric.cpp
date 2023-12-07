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
	:GeometricObject(base, height) // 기반클래스의 생성자 호출하여 line1, 2 초기화
{
	// 나머지 변수는 0으로 초기화
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
	side = sqrt((line1 / 2) * (line1 / 2) + line2 * line2); // 이등변삼각형 등변 계산
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
	:GeometricObject(base, height) // 기반클래스의 생성자 호출하여 line1, 2 초기화
{}

double Rectangle::Compute()
{
	return 0;
}

double Rectangle::AreaCalculation()
{
	return 0;
}



// 기반클래스 객체를 파생클래스로 다운 캐스팅
void DisplayGeometricObject(GeometricObject& object) // 여러 파생클래스를 파라미터로 받을 수 있음
{
	cout << "line1: " << object.GetLine1() << endl;
	cout << "line2: " << object.GetLine2() << endl;

	GeometricObject* p = &object;
	Isosceles* p1 = dynamic_cast<Isosceles*>(p); // 다운 캐스팅
	Rectangle* p2 = dynamic_cast<Rectangle*>(p); // 다른 파생클래스로도 동시에 다운 캐스팅 가능

	if (p1 != NULL) // 처음 파라미터로 들어온 객체가 Isosceles가 아니라면 p1는 NULL값이 됨
	{
		p1->AreaCalculation();
		p1->Compute();

		cout << "이등변삼각형의 넓이: " << p1->GetArea() << endl;
		cout << "이등변삼각형의 등변: " << p1->GetSide() << endl;
	}

	if (p2 != NULL)
	{
		cout << "p2 != NULL" << endl;
	}
}