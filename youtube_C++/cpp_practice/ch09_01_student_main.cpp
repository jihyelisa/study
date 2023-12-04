#include "ch09_01_student.h"

int main()
{
	Student p1; // 객체 생성 시 생성자도 함께 호출됨
	// 생성자에서 점수 값 초기화
	// 초기화 하지 않으면? - Garbage Value가 출력됨

	p1.ShowScore();

	cout << "*****************" << endl;

	p1.setScore(99, 93, 89);
	p1.SumAverage();
	p1.ShowScore();

	return 0;
}