#include <iostream>
using namespace std;

int main()
{
	int a = 100;
	int* pa;
	
	pa = &a; // pa에 a의 주소값 할당

	cout << "a에 저장된 값: " << a << endl; // a 일반변수에 담긴 값
	cout << "a의 주소: " << &a << endl; // &a 일반변수의 주소값

	cout << "a에 저장된 값: " << *pa << endl; // *pa 포인터변수에 담긴 주소가 가리키는 값
	cout << "a의 주소: " << pa << endl; // pa 포인터변수에 담긴 주소값

	a = 999;
	cout << "a에 저장된 값: " << *pa << endl; // 999
	cout << "a의 주소: " << pa << endl; // a의 주소값은 변하지 않음

	return 0;
}