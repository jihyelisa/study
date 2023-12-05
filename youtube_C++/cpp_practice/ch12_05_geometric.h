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

protected: // private은 파생클래스에서 접근할 수가 없음
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

// 이런 식으로 여러 도형으로 파생해 사용할 수 있음
class Rectangle :public GeometricObject
{
public:
	Rectangle(const double base, const double height);
	double AreaCalculation();
	double Compute();
};

// 다운 캐스팅을 위한 함수
void DisplayGeometricObject(GeometricObject& object);

#else
#endif