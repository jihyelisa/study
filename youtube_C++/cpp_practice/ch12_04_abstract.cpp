#include <iostream>
#include <string>
using namespace std;

class AbstractClass
{
public:
	virtual string SampleFunction() = 0; // overriding �Ǵ� ���� ������ ���������Լ�
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
	// ���� - �߻� Ŭ������ ��ü ���� �Ұ�

	// cout << obj.SampleFunction() << endl;

	return 0;
}