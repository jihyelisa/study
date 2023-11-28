#include <iostream>
using namespace std;

int main()
{
	int* pi;
	char* pc;
	float* pf;
	double* pd;

	int a = 100;
	pi = &a;

	char b = 'b';
	pc = &b;

	cout << sizeof(a) << endl; //4
	cout << sizeof(b) << endl; //1

	cout << "정수형 포인터 크기: " << sizeof(pi) << endl; //4
	cout << "문자형 포인터 크기: " << sizeof(pc) << endl; //4
	cout << "실수형 포인터 크기: " << sizeof(pf) << endl; //4
	cout << "배정도형 포인터 크기: " << sizeof(pd) << endl; //4

	return 0;
}