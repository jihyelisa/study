#include <iostream>
using namespace std;

int main()
{
	int score[3] = {99,88,100};

	// int �迭�̹Ƿ� �ּҰ��� 4�� ���̳�
	// int -> 4 byte �̹Ƿ�

	cout << "score[0]�� �ּ�: " << &score[0] << endl;
	cout << "score[1]�� �ּ�: " << &score[1] << endl;
	cout << "score[2]�� �ּ�: " << &score[2] << endl;

	cout << endl;

	cout << "score[0]�� �ּ�: " << score << endl; // �迭�̸����� �迭�ּҸ� ȣ���� �� ����
	cout << "score[1]�� �ּ�: " << score + 1 << endl;
	cout << "score[2]�� �ּ�: " << score + 2 << endl;

	return 0;
}