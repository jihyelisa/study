#include <iostream>
#include <exception>
using namespace std;

int main()
{
	try
	{
		for (int i = 1; i <= 100; i++)
		{
			new int[70000000]; // new ���� �� ���ܰ� �߻��� ��� catch�� ��
			cout << i << "��° �迭 ����" << endl;
		}
	}
	catch (bad_alloc& e) // new ���꿡 ���� ���� ó��
	{
		cout << "Exception: " << e.what() << endl;
	}

	return 0;
}