#include "ch11_02_str.h"

void StringCharArray::toCharArray(char* str)
{
	int i, len = this->length(); // ���� string ��ü�� ���� ��ȯ

	for (i = 0; i < len; i++)
		*(str + i) = this->at(i);

	*(str + i) = '\0';
};