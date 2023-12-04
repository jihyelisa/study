#include "ch11_03_a.h"

int main()
{
	A obj_A;

	obj_A.SetVar(10, 20);
	obj_A.ShowVar();
	//obj_A.proVar_A = 20; // protected 멤버는 해당 클래스 외부에서 참조 불가

	cout << "******************" << endl;

	B obj_B;

	obj_B.SetVar(30, 40); // 상속 받은 A의 함수들 참조 가능
	obj_B.ShowVar(); // protected 멤버인 proVar의 값 접근 가능
	obj_B.Show();

	return 0;
}