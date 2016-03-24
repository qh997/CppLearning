#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using namespace std;

#define SHOW(X) \
do { \
	cout << #X" = " << (X) << endl; \
} while(0)

int main()
{
	cout << fixed << setprecision(2);

	vector<Employee *> employees(4);
	employees[0] = new SalariedEmployee("John", "Smith", "111-11-111", 800);
	employees[1] = new HourlyEmployee("Karen", "Price", "222-22-222", 16.75, 40);
	employees[2] = new CommissionEmployee("Sue", "Jones", "333-33-333", 10000, .06);
	employees[3] = new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-444", 5000, .04, 300);

	for (size_t i = 0; i < employees.size(); i++)
	{
		employees[i]->print();
		cout << endl;

		BasePlusCommissionEmployee *derivedPtr =
			dynamic_cast<BasePlusCommissionEmployee *>
			(employees[i]);

		if (derivedPtr != NULL)
		{
			double oldBaseSalary = derivedPtr->getBase();
			SHOW(oldBaseSalary);
			derivedPtr->setBase(1.10 * oldBaseSalary);
			SHOW(derivedPtr->getBase());
		}
		else
		{
			SHOW(derivedPtr);
		}

		SHOW(employees[i]->earnings());
		cout << endl;
	}

	for (size_t i = 0; i < employees.size(); i++)
	{
		SHOW(typeid(*employees[i]).name());
	}

	SHOW(typeid(employees[0]).name());
	SHOW(typeid(employees).name());

	SalariedEmployee se("John", "Smith", "111-11-111", 997);
	SHOW(typeid(se).name());

	int aaa[9];
	SHOW(typeid(aaa).name());
}
