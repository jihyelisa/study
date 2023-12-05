#include "ch12_05_geometric.h"

int main()
{
	Isosceles tri(4.2, 5.4);

	cout << "삼각형 밑변: " << tri.GetLine1() << endl;
	cout << "삼각형 높이: " << tri.GetLine2() << endl;
	cout << "넓이: " << tri.AreaCalculation() << endl;
	cout << "등변: " << tri.Compute() << endl;

	// 여러가지 도형으로 파생 가능
	Rectangle rect(1, 2);
	

	GeometricObject* p1 = new Isosceles(9, 15); // 파생클래스 객체를 기반클래스로 업 캐스팅 (자동으로 형변환 됨)
	Isosceles* p2 = new Isosceles(5, 6);
	cout << "p1: " << p1->GetLine1() << endl;
	cout << "p2: " << p2->GetLine1() << endl;


	Isosceles p3(9, 15);
	Rectangle p4(3, 7);

	DisplayGeometricObject(p3); // 다운 캐스팅을 위한 함수
	DisplayGeometricObject(p4);

	return 0;
};