#include <iostream>
using namespace std;

int main()
{
	int i;

	//for (i = 1; i <= 3; i++)
	//	cout << "i = " << i << endl;

	i = 1;
	for (; i <= 3; )
	{
		cout << "i = " << i << endl;
		i++;
	}
}