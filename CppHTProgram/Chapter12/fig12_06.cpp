#include <iostream>
#include <string>
#include "CommissionEmployee.h"

using namespace std;

#define SHOW(X) \
do { \
	cout << #X" = " << (X) << endl; \
} while(0)

int main()
{
	CommissionEmployee ce("Sue", "Jones", "222-222-222", 10000, .06);

	ce.print();
	cout << endl;

	SHOW(ce.earnings());
}
