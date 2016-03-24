#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee
{
public:
	Employee(const std::string &frist, const std::string &last, 
		const std::string ssn);
	~Employee();

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

	virtual double earnings() const = 0;
	virtual void print() const;

private:
	std::string fristName;
	std::string lastName;
	std::string ssNumber;
};

#endif
