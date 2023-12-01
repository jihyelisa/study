#include "config.h"

int TotalCalculation(int jumsu[], int num)
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

	return tot;
}