#include <iostream>
using namespace std;

int main()
{
	int a = 20, b = 3;
	float c, d;

	c = a / 3.5f; //3.5를 double형이 아닌 float형으로 만들려면: (float)3.5, 3.5f

	// 둘다 가능
	d = (float)a / b;
	d = static_cast<float>(a) / b;

	cout.setf(ios::fixed, ios::floatfield); // 소수점 이하를 처리하고, 표시
	cout << "연산 결과: 실수형 = " << c << endl;
	cout << "연산 결과: 정수형 = " << d << endl;
}