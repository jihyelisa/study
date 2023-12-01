#include "config.h"

int TotalCalculation(const int jumsu[], const int num) // jumsu와 num을 위한 메모리 공간이 새로 확보됨
{
	int tot = 0, i;

	if (num < 0)
		return -1;

	for (i = 0; i < num; i++)
	{
		if (jumsu[i] < 0 || jumsu[i]>100)
			return -1;
		
		tot += jumsu[i];
	}

	return tot; // return을 만나면 함수를 위해 확보된 메모리 공간들이 해제됨
}