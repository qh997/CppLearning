#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <iostream>
#include <string>
#include "Employee.h"

class HourlyEmployee : public Employee
{
public:
	HourlyEmployee(const std::string &frist, const std::string &last, 
		const std::string ssn, double hourlyWage = 0.0, double hoursWorked = 0.0);
	~HourlyEmployee();

	void setWage(double hourlyWage);
	double getWage() const;

	void setHours(double hours);
	double getHours() const;

	virtual double earnings() const;
	virtual void print() const;

private:
	double wage;
	double hours;
};

#endif
