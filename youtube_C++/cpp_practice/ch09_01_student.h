#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
using namespace std;

class Student
{
public:
	Student(); // 생성자, constructor
	Student(const int s1, const int s2, const int s3); // 파라미터가 있는 생성자
	~Student();
	void setScore(const int s1, const int s2, const int s3);
	void ShowScore();
	void SumAverage();
private:
	int score[3], sum;
	double average;
};

#else
#endif