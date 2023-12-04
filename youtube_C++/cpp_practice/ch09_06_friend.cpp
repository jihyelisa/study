#include <iostream>
using namespace std;

class SaleInf
{
	friend int CheckTax2(SaleInf& Obj); //멤버가 아닌 함수에 friend 사용 - 멤버와 같은 접근권한을 가짐

public:
	SaleInf(const double Income);
	double getTax();
private:
	double Income;
	double Tax;
};

SaleInf::SaleInf(const double Income)
{
	this->Income = Income;
}

double SaleInf::getTax()
{
	return Tax;
}

int CheckTax2(SaleInf& Obj)
{
	if (Obj.Income <= 0)
		return 0;

	Obj.Tax = Obj.Income * 0.03;
	return 1;
}

int main()
{
	SaleInf s1(20.4);
	CheckTax2(s1);

	cout << "세금: " << s1.getTax() << endl;

	return 0;
}