#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream output; //��� ���� ��ü ����
	char cont = 'y';
	char word[50] = { 0, };

	output.open("test.txt"); //��� ���� ����

	if (output.fail())
		return 1;

	while (cont == 'y' || cont == 'Y')
	{
		cout << "�ܾ� �Է�: ";
		cin >> word; //ǥ�� �Է� ��ġ - Ű����� �ڷ� �Է�

		output << word << endl; // ��� ���Ͽ� ���� ���

		cout << "����Ͻðڽ��ϱ�? (y/n) ";
		cin >> cont;
	}

	output.close(); //���� �ݱ�

	return 0;
}