#include <iostream>
#pragma warning (disable: 4290)
using namespace std;

// 함수 안에서 사용할 때는 함수 선언 시 throw 명시해주기
//void ThrowFunc(const int n) throw (int);

// try 안에서 호출할 경우 함수 안의 throw도 예외처리에 사용 가능
//void ThrowFunc(const int n) throw (int)
//{
//	if (n == 0)
//		throw n;
//}

int main()
{
	int number1, number2;
	int quotient, reminder;

	cout << "수1: ";
	cin >> number1;
	cout << "수2: ";
	cin >> number2;

	try
	{
		if (number2 == 0)
			throw number1; // 예외처리 // number1 값을 가지고 catch로 감

		quotient = number1 / number2;
		reminder = number1 % number2;

		cout << "몫: " << quotient << endl;
		cout << "나머지: " << reminder << endl;
	}
	catch (int e_num)
	{
		cout << e_num << "은 0으로 나눌 수 없습니다." << endl;
	}
}