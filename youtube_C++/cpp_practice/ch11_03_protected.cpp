#include "ch11_03_a.h"

int main()
{
	A obj_A;

	obj_A.SetVar(10, 20);
	obj_A.ShowVar();
	//obj_A.proVar_A = 20; // protected ����� �ش� Ŭ���� �ܺο��� ���� �Ұ�

	cout << "******************" << endl;

	B obj_B;

	obj_B.SetVar(30, 40); // ��� ���� A�� �Լ��� ���� ����
	obj_B.ShowVar(); // protected ����� proVar�� �� ���� ����
	obj_B.Show();

	return 0;
}