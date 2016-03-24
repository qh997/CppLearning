#include <iostream>
#include <iomanip>
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using namespace std;

int main()
{
	CommissionEmployee ce("Sue", "Jones", "222-222-222", 10000, .06);
	CommissionEmployee *cePtr = NULL;
	BasePlusCommissionEmployee bce("Bob", "Lewis", "333-33-333", 5000, .04, 300);
	BasePlusCommissionEmployee *bcePtr = NULL;

	cout << fixed << setprecision(2);

	ce.print();
	cout << "\n" << endl;

	bce.print();
	cout << "\n" << endl;

	cePtr = &ce;
	cePtr -> print();
	cout << "\n" << endl;

	bcePtr = &bce;
	bcePtr -> print();
	cout << "\n" << endl;

	cePtr = bcePtr;
	cePtr -> print();
	cout << "\n" << endl;
}
