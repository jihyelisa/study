#include "ch11_03_a.h"

void A::SetVar(const int proVar_A, const int priVar_A)
{
	this->proVar_A = proVar_A;
	this->priVar_A = priVar_A;
}

void A::ShowVar()
{
	cout << "proVar_A = " << proVar_A << endl;
	cout << "priVar_A = " << priVar_A << endl;
}

void B::Show()
{
	b = 20;
	cout << "b = " << b << endl;
	proVar_A = 200; // protected ����� proVar�� �� ���� ����
	//priVar_A = 300; // private ����� priVar�� �� ���� �Ұ�
	cout << "proVar_A = " << proVar_A << endl;
}