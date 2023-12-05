#include <iostream>
using namespace std;

class A
{
public:
	virtual string ClassMessage() // overriding �� ��� Ŭ������ �Լ��� virtual �Լ����� ��
	{
		return "class A";
	}
};

class B : public A
{
public:
	string ClassMessage() // ��� Ŭ������ �Լ� overriding
	{
		return "class B";
	}
};



void TestFunc(A *x) // �ּҰ��� �����ؾ� ��
// �׳� ��ü�� ������ ���?
// dynamic binding�� �Ͼ�� �ʾ� overriding ����x
{
	cout << x->ClassMessage().data() << endl;
}



int main()
{
	A a;
	B b;

	TestFunc(&a);
	TestFunc(&b);

	return 0;
}