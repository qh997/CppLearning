#include <iostream>
#include <string>
#include "Array.h"

using namespace std;

#define SHOW(X) \
do { \
	cout << #X" = " << (X) << endl; \
} while(0)

void outputArray(const Array &a)
{
	SHOW(a);
}

int main()
{
	Array a(7);

	SHOW(a);

	outputArray(Array(8));
}
