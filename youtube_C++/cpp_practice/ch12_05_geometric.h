#ifndef _GEOMETRIC_H_
#define _GEOMETRIC_H_

#include <iostream>
using namespace std;

class GeometricObject
{
public:
	GeometricObject();
	GeometricObject(const double line1, const double line2);
	void SetLine1(const double line1);
	void SetLine2(const double line2);
	double GetLine1();
	double GetLine2();
	virtual double AreaCalculation() = 0;
	virtual double Compute() = 0;

protected: // private�� �Ļ�Ŭ�������� ������ ���� ����
	double line1, line2;
};

class Isosceles :public GeometricObject
{
public:
	Isosceles();
	Isosceles(const double base, const double height);
	double AreaCalculation();
	double Compute();
	double GetSide();
	double GetArea();

private:
	double side;
	double area;
};

// �̷� ������ ���� �������� �Ļ��� ����� �� ����
class Rectangle :public GeometricObject
{
public:
	Rectangle(const double base, const double height);
	double AreaCalculation();
	double Compute();
};

// �ٿ� ĳ������ ���� �Լ�
void DisplayGeometricObject(GeometricObject& object);

#else
#endif