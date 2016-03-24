#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>
#include "CommissionEmployee.h"

using std::string;

class BasePlusCommissionEmployee
	: public CommissionEmployee
{
public:
	BasePlusCommissionEmployee(
		const std::string &frist, const std::string &last, 
		const std::string ssn, double sales = 0.0, double rate = 0.0,
		double base = 0.0);
	~BasePlusCommissionEmployee();

	void setBase(double base);
	double getBase() const;

	double earnings() const;
	void print() const;

private:
	double baseSalary;
};

#endif
