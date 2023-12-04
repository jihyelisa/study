#include "ch09_01_student.h"

int main()
{
	Student p1; // 객체 생성 시 생성자도 함께 호출됨
	// 생성자에서 점수 값 초기화
	// 초기화 하지 않으면? - Garbage Value가 출력됨

	p1.ShowScore();

	p1.setScore(99, 93, 89);
	p1.SumAverage();
	p1.ShowScore();

	Student p2(90, 98, 76); // 파라미터가 있는 생성자 호출
	p2.SumAverage();
	p2.ShowScore();

	Student p3(p1); // 복사 생성자, copy contructure
	// 객체를 파라미터로 전달함
	// 단, 복사 생성자는 컴파일러가 합성해주는 생성자이므로 파라미터에 포함되지 않은 sum, average 값은 초기화x
	p3.SumAverage();
	p3.ShowScore();

	Student* p4; // 포인터 객체, pointer to object
	// 값 초기화 안 됨
	// 객체가 아니고 포인터이기 때문에 소멸자 호출x
	p4 = &p2;
	p4->ShowScore();

	Student* p5 = new Student(86, 75, 90); // 동적할당
	p5->SumAverage();
	p5->ShowScore();
	delete(p5); // 소멸자 호출됨

	Student& p6 = p1; // 참조 객체
	p6.ShowScore();

	return 0;
}