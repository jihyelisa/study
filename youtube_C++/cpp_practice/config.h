// preprocessor�� �̿��� ��������� �ߺ��ؼ� ���� �ʵ��� ��
#ifndef _CONFIG_H_ // _CONFIG_H_�� ���ǵǾ� ���� �ʴٸ�
#define _CONFIG_H_ // �Ʒ��� _CONFIG_H_�� �����϶�

#include <iostream>
using namespace std;

typedef struct sam
{
	char Name[30];
	char MPhoneNum[20];
} SAM;

int TotalCalculation(int jumsu[], int num); //�Լ� ����

#else // ���ǵǾ� �ִٸ�
// �ƹ��͵� �������� ���ƶ�
#endif