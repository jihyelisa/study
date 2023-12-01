#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
using namespace std;

class Student
{
public:
	Student(); // »ý¼ºÀÚ, constructor
	void setScore(const int s1, const int s2, const int s3);
	void ShowScore();
	void SumAverage();
private:
	int score[3], sum;
	double average;
};

#else
#endif