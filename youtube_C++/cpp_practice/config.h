// preprocessor를 이용해 헤더파일을 중복해서 읽지 않도록 함
#ifndef _CONFIG_H_ // _CONFIG_H_가 정의되어 있지 않다면
#define _CONFIG_H_ // 아래의 _CONFIG_H_를 정의하라

#include <iostream>
using namespace std;

typedef struct sam
{
	char Name[30];
	char MPhoneNum[20];
} SAM;

int TotalCalculation(const int jumsu[], const int num); //함수 선언
// const?
// 함수 안에서 값을 사용만 할 뿐 변경하지 않을 것임

#else // 정의되어 있다면
// 아무것도 실행하지 말아라
#endif