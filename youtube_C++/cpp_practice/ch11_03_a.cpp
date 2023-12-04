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
	proVar_A = 200; // protected 멤버인 proVar의 값 접근 가능
	//priVar_A = 300; // private 멤버인 priVar의 값 접근 불가
	cout << "proVar_A = " << proVar_A << endl;
}