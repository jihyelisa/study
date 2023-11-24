#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	int sum;

	cout << "정수1 입력: ";
	cin >> num1;

	cout << "정수2 입력: ";
	cin >> num2;

	sum = num1 + num2;

	cout << num1 << "+" << num2 << "=" << sum << endl;

	return 0;
}