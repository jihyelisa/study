#include <iostream>

namespace TEST
{
	int a = 200;
}



using namespace std;
// using?
// ������ �� ���� �ƴ� ���� ������ std ���ӽ����̽��� ���� ã�ƺ����� ��

int main()
{
	cout << "****" << endl;
	cout << TEST::a << endl;

	return 0;
}