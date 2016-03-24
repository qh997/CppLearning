#include <iostream>
#include <string>
#include "BasePlusCommissionEmployee.h"

using namespace std;

#define SHOW(X) \
do { \
	cout << #X" = " << (X) << endl; \
} while(0)

int main()
{
	BasePlusCommissionEmployee ce("Sue", "Jones", "222-222-222", 10000, .06, 300);

	ce.print();
	cout << endl;

	SHOW(ce.earnings());

	SHOW(sizeof(BasePlusCommissionEmployee));
	SHOW(sizeof(CommissionEmployee));
	SHOW(sizeof(double));
}