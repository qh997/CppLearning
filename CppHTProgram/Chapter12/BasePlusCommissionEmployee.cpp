#include <iostream>
#include <string>
#include "BasePlusCommissionEmployee.h"

using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
	const std::string &frist, const std::string &last, 
	const std::string ssn, double sales, double rate,
	double base)
	: CommissionEmployee(frist, last, ssn, sales, rate)
{
	cout << "BasePlusCommissionEmployee constructor." << endl;
	setBase(base);
}

BasePlusCommissionEmployee::~BasePlusCommissionEmployee()
{
	cout << "BasePlusCommissionEmployee destructor." << endl;
}

void BasePlusCommissionEmployee::setBase(double base)
{
	baseSalary = base < 0.0 ? 0.0 : base;
}

double BasePlusCommissionEmployee::getBase() const
{
	return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const
{
	return getBase() + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const
{
	CommissionEmployee::print();

	cout << "\nBase Salary: " << getBase();
}
