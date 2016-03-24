#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <iostream>
#include <string>
#include "Employee.h"

class SalariedEmployee : public Employee
{
public:
	SalariedEmployee(const std::string &frist, const std::string &last, 
		const std::string ssn, double salary = 0.0);
	~SalariedEmployee();

	void setWeeklySalary(double salary);
	double getWeeklySalary() const;

	virtual double earnings() const;
	virtual void print() const;

private:
	double weeklySalary;
};

#endif
