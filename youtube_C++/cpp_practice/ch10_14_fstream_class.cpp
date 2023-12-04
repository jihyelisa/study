#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	fstream fs;

	// ��� ���� ��
	fs.open("test.txt", ios::out);
	
	if (fs.fail())
		return 0;

	fs << "keyboard" << endl;
	fs << "monitor" << endl;
	fs.close();



	// append ���� �� - �� �ڿ� ���� �߰�
	fs.open("test.txt", ios::app);
	fs << "desk" << endl;
	fs.close();



	// �Է� ���� ��
	fs.open("test.txt", ios::in);
	string temp;

	while (fs >> temp, !fs.eof())
	{
		cout << temp << endl;
	}

	fs.close();



	// �������� ���
	int scoreArr[5] = { 78, 96, 100, 25, 96 };
	fs.open("sample.bin", ios::out | ios::binary); // ��� �������� ����
	fs.write((char*)scoreArr, 20); // score ��ġ���� 20����Ʈ ���
	fs.close();



	// �������� �Է�
	fs.open("sample.bin", ios::in | ios::binary); // �Է� - ��������
	if (fs.fail()) // ���� ���� ���� �� ���α׷� ����
		return 1;

	int score;
	while (fs.read((char*)&score, 4), !fs.eof())
		cout << setw(3) << right << score << endl;

	fs.close();

	return 0;
}