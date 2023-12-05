#include <iostream>
#include <string>
using namespace std;

class AbstractClass
{
public:
	virtual string SampleFunction() = 0; // overriding 되는 것이 목적인 순수가상함수
};

class TestClass :public AbstractClass
{
public:
	string SampleFunction()
	{
		return "Sample Function";
	}
};

int main()
{
	// AbstractClass obj;
	// 에러 - 추상 클래스는 객체 생성 불가

	// cout << obj.SampleFunction() << endl;

	return 0;
}