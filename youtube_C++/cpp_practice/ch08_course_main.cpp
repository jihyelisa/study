#include "ch08_course.h"

int main()
{
	Course c1;
	char CourseN[30];
	char ch = 'y', n[30], name[10][30];

	cout << "Enter the course name: ";
	cin >> CourseN;

	c1.setCourseName(CourseN);

	while (ch == 'y' || ch == 'Y')
	{
		cout << "Enter the student name: ";
		cin >> n;

		c1.setName(n);

		cout << "Continue? (y/n) ";
		cin >> ch;
	}

	c1.getCourseName(CourseN);
	cout << "\nCourse Name: " << CourseN << endl;
	cout << "\nStudent List:" << endl;

	c1.getName(name);

	for (int i = 0; i < c1.getCount(); i++)
		cout << name[i] << "   ";

	cout << "\n\nTotal student number: " << c1.getCount();

	return 0;
}