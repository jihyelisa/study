#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int i;
	cout << "  | ";

	for (i = 1; i <= 9; i++)
		cout << setw(3) << i;

	cout << "\n-----------------------\n";

	for (i = 1; i <= 9; i++)
	{
		cout << i << " | ";
		for (int j = 1; j <= 9; j++)
			cout << setw(3) << i * j;
		cout << "\n";
	}
}