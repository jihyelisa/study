#include <iostream>
using namespace std;

class A
{
public:
	virtual string ClassMessage() // overriding 할 기반 클래스의 함수가 virtual 함수여야 함
	{
		return "class A";
	}
};

class B : public A
{
public:
	string ClassMessage() // 기반 클래스의 함수 overriding
	{
		return "class B";
	}
};



void TestFunc(A *x) // 주소값을 전달해야 함
// 그냥 객체를 전달할 경우?
// dynamic binding이 일어나지 않아 overriding 적용x
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