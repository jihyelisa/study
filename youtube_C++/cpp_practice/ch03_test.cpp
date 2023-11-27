#include <iostream>

namespace TEST
{
	int a = 200;
}



using namespace std;
// using?
// 컴파일 시 예약어가 아닌 것이 나오면 std 네임스페이스로 가서 찾아보도록 함

int main()
{
	cout << "****" << endl;
	cout << TEST::a << endl;

	return 0;
}