#include "ch11_07_conTest.h"

int main()
{
	CON2* p_TEST = new CON2;

	delete p_TEST;

	return 0;
}

// 실행 결과
// CON1 생성자
// CON2 생성자
// CON2 소멸자
// CON1 소멸자

// 실제 실행 순서
// 파생 클래스의 머리 ({} 위의 내용)
// 기반 클래스 (CON1 생성자)
// 파생 클래스의 몸통 (CON2 생성자)