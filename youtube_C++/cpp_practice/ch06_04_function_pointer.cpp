#include <iostream>
using namespace std;

int TestFunc1(int a);
int TestFunc2(int& a);
int TestFunc3(int* a);
int TestFunc4(int a = 888); //파라미터 넣지 않을 경우 디폴트 값으로 전달됨

int main()
{
	int b = 200;
	int& r_b = b;
	cout << "b = " << b << endl;

	cout << "TestFunc1(b)" << endl;
	TestFunc1(b);
	cout << "b = " << b << endl;

	cout << "TestFunc1(999)" << endl;
	TestFunc1(999);
	cout << "b = " << b << endl;

	cout << "TestFunc2(r_b)" << endl;
	TestFunc2(r_b); // 레퍼런스 변수로 b의 주소값을 전달
	cout << "b = " << b << endl; //777

	cout << "TestFunc3(&b)" << endl;
	TestFunc3(&b);
	cout << "b = " << b << endl; //999

	cout << "TestFunc4(b)" << endl;
	TestFunc4(b);
	cout << "b = " << b << endl;

	cout << "TestFunc4()" << endl;
	TestFunc4();
	cout << "b = " << b << endl;

	return 0;
}

int TestFunc1(int a)
{
	cout << "a = " << a << endl;
	a = 100;
	cout << "a = " << a << endl;

	return 0;
}

int TestFunc2(int& a)
{
	cout << "a = " << a << endl;
	a = 777;
	cout << "a = " << a << endl;

	return 0;
}

int TestFunc3(int* a)
{
	cout << "*a = " << *a << endl;
	*a = 999;
	cout << "*a = " << *a << endl;

	return 0;
}

int TestFunc4(int a)
{
	cout << "a = " << a << endl;

	return 0;
}