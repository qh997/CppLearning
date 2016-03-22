#include <iostream>
#include "Array.h"

using namespace std;

#define SHOW(X) \
do { \
	cout << #X" = " << (X) << endl; \
} while(0)

int main()
{
	Array integers1(7);
	Array integers2;

	cout << integers1;

	SHOW(integers1.getSize());
	SHOW(integers2.getSize());

	integers1[0] = 12;

	SHOW(integers1[0]);

	int x = integers1[0];
	SHOW(x);
	x = 23;
	SHOW(integers1[0]);

	int &y = integers1[0];
	SHOW(y);
	y = 23;
	SHOW(integers1[0]);

	const Array integers3(2);
	SHOW(integers3.getSize());
	SHOW(integers3[1]);

	const int z = integers1[0];

	SHOW(integers1 != integers2);

	return 0;
}
