#include "ch11_07_conTest.h"

int main()
{
	CON2* p_TEST = new CON2;

	delete p_TEST;

	return 0;
}

// ���� ���
// CON1 ������
// CON2 ������
// CON2 �Ҹ���
// CON1 �Ҹ���

// ���� ���� ����
// �Ļ� Ŭ������ �Ӹ� ({} ���� ����)
// ��� Ŭ���� (CON1 ������)
// �Ļ� Ŭ������ ���� (CON2 ������)