#include "ch13_06_time.h"

int main()
{
	Time t1(7, 30, 20);

	cout << t1.ShowTime() << endl;
	cout << "시간 - 초단위: " << t1.CalSec() << endl;

	Time t2(4, 50, 23);

	if (t1 <= t2)
		cout << t1.ShowTime() << "이 " << t2.ShowTime() << "보다 작거나 같다." << endl;
	else
		cout << t1.ShowTime() << "이 " << t2.ShowTime() << "보다 크다." << endl;
}