#include "ch08_course.h"

void Course::setCourseName(const char c[])
{
	strcpy_s(CourseName, 30, c);
	Count = 0;
}

void Course::setName(const char n[])
{
	strcpy_s(Name[Count], 30, n);
	Count++;
};

int Course::getCourseName(char c[])
{
	if (Count == 0)
		return 0;

	strcpy_s(c, 30, CourseName);

	return 1;
};

int Course::getName(char n[][30])
{
	if (Count == 0)
		return 0;

	for (int i = 0; i < Count; i++)
		strcpy_s(n[i], 30, Name[i]);

	return 1;
};

int Course::getCount()
{
	return Count;
}