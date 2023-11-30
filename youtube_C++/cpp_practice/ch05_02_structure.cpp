#include <iostream>
#include <string>
using namespace std;

int main()
{
	struct SAM // 구조체 태그
	{
		char Name[30]; //구조체 멤버
		char MPhoneNum[20];
	};
	
	// struct SAM Friend, Friend1;
	SAM Friend, Friend1; // struct 생략 가능

	strcpy_s(Friend.Name, 30, "김갑돌");
	strcpy_s(Friend.MPhoneNum, 20, "010-1234-5678");

	cout << Friend.Name << endl;
	cout << Friend.MPhoneNum << endl;

	Friend1 = Friend; // 구조체 변수에 넣을 수 있음

	cout << Friend1.Name << endl;
	cout << Friend1.MPhoneNum << endl;

	// 구조체 멤버로 다른 구조체를 넣을 수도 있음

	return 0;
}