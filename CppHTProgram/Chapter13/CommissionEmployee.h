#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include <iostream>
#include <string>
#include "Employee.h"

class CommissionEmployee : public Employee
{
public:
	CommissionEmployee(const std::string &frist, const std::string &last, 
		const std::string ssn, double sales = 0.0, double rate = 0.0);
	~CommissionEmployee();

	void setFrist(const std::string &frist);
	std::string getFrist() const;

	void setLast(const std::string &last);
	std::string getLast() const;

	void setSSN(const std::string &ssn);
	std::string getSSN() const;

	void setSales(double sales);
	double getSales() const;

	void setRate(double rate);
	double getRate() const;

	virtual double earnings() const;
	virtual void print() const;

private:
	double grossSales;
	double commissionRate;
};

#endif
