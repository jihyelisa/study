#include <iostream>
using namespace std;

int main()
{
	int a=10;

	a++;

	cout << "a = " << a << endl; //11
	cout << "a = " << a++ << endl; //11

	cout << "a = " << ++a << endl; //13
	cout << "a = " << a << endl; //13

	return 0;
}