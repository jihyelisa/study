#include "ch11_02_str.h"

void StringCharArray::toCharArray(char* str)
{
	int i, len = this->length(); // 현재 string 객체의 길이 반환

	for (i = 0; i < len; i++)
		*(str + i) = this->at(i);

	*(str + i) = '\0';
};