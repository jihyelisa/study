#ifndef _TIME_H_
#define _TIME_H_

#include <iostream>
#include <string>
#define HOUR_SEC 3600
#define MIN_SEC 60
using namespace std;

class Time
{
public:
	Time();
	Time(const int hour, const int min, const int sec);
	void SetHour(const int hour);
	void SetMin(const int min);
	void SetSec(const int sec);
	int GetHour();
	int GetMin();
	int GetSec();
	int CalSec();
	string ShowTime();

	bool operator<=(Time timeObj);

private:
	int hour, min, sec;
	int t_sec;
};

#else
#endif