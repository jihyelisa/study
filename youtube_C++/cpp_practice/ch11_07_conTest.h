#ifndef _CONTEST_H_
#define _CONTEST_H_

#include <iostream>
using namespace std;

class CON1
{
public:
	CON1();
	~CON1();
};

class CON2:public CON1
{
public:
	CON2();
	~CON2();
};

#else
#endif