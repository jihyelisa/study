#include <iostream>
using namespace std;

int main()
{
	int a = 20, b = 3;
	float c, d;

	c = a / 3.5f; //3.5�� double���� �ƴ� float������ �������: (float)3.5, 3.5f

	// �Ѵ� ����
	d = (float)a / b;
	d = static_cast<float>(a) / b;

	cout.setf(ios::fixed, ios::floatfield); // �Ҽ��� ���ϸ� ó���ϰ�, ǥ��
	cout << "���� ���: �Ǽ��� = " << c << endl;
	cout << "���� ���: ������ = " << d << endl;

	
	cout << sizeof(int) << "byte" << endl;
	cout << sizeof(char) << "byte" << endl;
	cout << sizeof(float) << "byte" << endl;
	cout << sizeof(double) << "byte" << endl;

	return 0;
}