#include <iostream>
using namespace std;

int main()
{
	int a=10;

	a++;

	cout << "a = " << a << endl;
	cout << "a = " << a++ << endl;

	cout << "a = " << ++a << endl;
	cout << "a = " << a << endl;

	return 0;
}