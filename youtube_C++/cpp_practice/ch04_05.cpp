#include <iostream>
using namespace std;

int main()
{
	int score[3] = {99,88,100};

	// int 배열이므로 주소값이 4씩 차이남
	// int -> 4 byte 이므로

	cout << "score[0]의 주소: " << &score[0] << endl;
	cout << "score[1]의 주소: " << &score[1] << endl;
	cout << "score[2]의 주소: " << &score[2] << endl;

	cout << endl;

	cout << "score[0]의 주소: " << score << endl; // 배열이름으로 배열주소를 호출할 수 있음
	cout << "score[1]의 주소: " << score + 1 << endl;
	cout << "score[2]의 주소: " << score + 2 << endl;

	return 0;
}