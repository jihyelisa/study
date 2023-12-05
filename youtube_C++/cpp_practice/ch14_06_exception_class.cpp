#include <iostream>
#include <exception>
using namespace std;

int main()
{
	try
	{
		for (int i = 1; i <= 100; i++)
		{
			new int[70000000]; // new 연산 중 예외가 발생할 경우 catch로 감
			cout << i << "번째 배열 생성" << endl;
		}
	}
	catch (bad_alloc& e) // new 연산에 의한 예외 처리
	{
		cout << "Exception: " << e.what() << endl;
	}

	return 0;
}