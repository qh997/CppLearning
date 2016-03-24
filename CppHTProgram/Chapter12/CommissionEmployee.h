#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include <iostream>
#include <string>

class CommissionEmployee
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

	double earnings() const;
	void print() const;

private:
	std::string fristName;
	std::string lastName;
	std::string ssNumber;
	double grossSales;
	double commissionRate;
};

#endif
