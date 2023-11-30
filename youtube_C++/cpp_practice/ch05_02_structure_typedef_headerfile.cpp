#include "config.h"

int main()
{
	SAM friend1 = { "Lisa", "010-1234-5678" }, friend2;

	cout << friend1.Name << endl;
	cout << friend1.MPhoneNum << endl;

	return 0;
}