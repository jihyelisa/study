#include "ch13_06_time.h"

Time::Time()
{
	hour = 0;
	min = 0;
	sec = 0;
}

Time::Time(const int hour, const int min, const int sec)
{
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}

void Time::SetHour(const int hour)
{
	this->hour = hour;
}
void Time::SetMin(const int min)
{
	this->min = min;
}
void Time::SetSec(const int sec)
{
	this->sec = sec;
}
int Time::GetHour() {
	return hour;
}
int Time::GetMin() {
	return min;
}
int Time::GetSec() {
	return sec;
}

int Time::CalSec()
{
	t_sec = hour * HOUR_SEC + min * MIN_SEC + sec;

	return t_sec;
}

string Time::ShowTime()
{
	char c_hour[50] = { 0, }, c_min[50] = { 0, }, c_sec[50] = { 0, };

	_itoa_s(hour, c_hour, 50, 10);
	_itoa_s(min, c_min, 50, 10);
	_itoa_s(sec, c_sec, 50, 10);

	strcat_s(c_hour, 50, "시 ");
	strcat_s(c_min, 50, "분 ");
	strcat_s(c_sec, 50, "초");

	strcat_s(c_hour, 50, c_min);
	strcat_s(c_hour, 50, c_sec);

	return string(c_hour);
}

bool Time::operator<=(Time timeObj) // operator overloading
{
	this->CalSec(); // 자신의 값
	timeObj.CalSec(); // 매개변수의 값

	if (this->t_sec <= timeObj.t_sec)
		return true;
	else
		return false;
}