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

	cout << "������ ������ ũ��: " << sizeof(pi) << endl; //4
	cout << "������ ������ ũ��: " << sizeof(pc) << endl; //4
	cout << "�Ǽ��� ������ ũ��: " << sizeof(pf) << endl; //4
	cout << "�������� ������ ũ��: " << sizeof(pd) << endl; //4

	return 0;
}