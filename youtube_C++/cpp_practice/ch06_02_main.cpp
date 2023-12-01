#include "config.h"

int main()
{
	int s[6] = { 100, 90, 76, 89, 100, 88 };
	int total;
	float aver;

	total = TotalCalculation(s, 6);

	if (total == -1)
		return 1;

	cout << "รัมก: " << total << endl;

	return 0;
}