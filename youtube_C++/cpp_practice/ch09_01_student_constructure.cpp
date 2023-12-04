#include "ch09_01_student.h"

Student::Student() // 생성자 정의
	: sum(0), average(0)
{
	score[0] = 0;
	score[1] = 0;
	score[2] = 0;

	// 위의 '생성자 초기화 목록'으로 대체 가능 - 원하는 클래스 멤버를 초기화 해줌
	// sum = 0;
	// average = 0;
};

Student::Student(const int s1, const int s2, const int s3) // 파라미터가 있는 생성자 정의
{
	score[0] = s1;
	score[1] = s2;
	score[2] = s3;

	sum = 0;
	average = 0;
};

Student::~Student()
{
	cout << "소멸자 호출로 객체 소멸" << endl; //생성된 객체 수만큼 호출됨
}

void Student::setScore(const int s1, const int s2, const int s3)
{
	score[0] = s1;
	score[1] = s2;
	score[2] = s3;
};

void Student::SumAverage()
{
	cout << "sum:" << sum << endl;
	cout << "average:" << average << endl;

	int i;
	for (i = 0; i < 3; i++)
		sum = sum + score[i];

	average = sum / 3;
};

void Student::ShowScore()
{
	int i;
	for (i = 0; i < 3; i++)
		cout << "점수" << i + 1 << ": " << score[i] << endl;
	
	cout << "총점: " << sum << endl;
	cout << "평균: " << average << endl;

	cout << "*****************" << endl;
}