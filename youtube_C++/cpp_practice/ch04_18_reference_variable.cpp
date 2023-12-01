#include <iostream>
using namespace std;

int main()
{
	// 레퍼런스 변수
	// 이미 선언한 변수에 추가로 이름을 부여하는 것

	int a = 100;
	int& ra = a;

	ra = 200;

	cout << "a = " << a << endl; //200
	cout << "ra = " << ra << endl; //200

	cout << "&a = " << &a << endl;
	cout << "&ra = " << &ra << endl; // 위와 동일한 주소값

	return 0;
}