#include <iostream>
#include <string>
#include "CommissionEmployee.h"

using namespace std;

CommissionEmployee::CommissionEmployee(const string &frist, const string &last, 
	const string ssn, double sales, double rate)
	: fristName(frist), lastName(last), ssNumber(ssn)
{
	cout << "CommissionEmployee constructor." << endl;
	setFrist(frist);
	setLast(last);
	setSSN(ssn);
	setSales(sales);
	setRate(rate);
}

CommissionEmployee::~CommissionEmployee()
{
	cout << "CommissionEmployee destructor." << endl;
}

void CommissionEmployee::setFrist(const string &frist)
{
	fristName = frist;
}

string CommissionEmployee::getFrist() const
{
	return fristName;
}

void CommissionEmployee::setLast(const string &last)
{
	lastName = last;
}

string CommissionEmployee::getLast() const
{
	return lastName;
}

void CommissionEmployee::setSSN(const string &ssn)
{
	ssNumber = ssn;
}

string CommissionEmployee::getSSN() const
{
	return ssNumber;
}

void CommissionEmployee::setSales(double sales)
{
	grossSales = sales < 0.0 ? 0.0 : sales;
}
double CommissionEmployee::getSales() const
{
	return grossSales;
}

void CommissionEmployee::setRate(double rate)
{
	commissionRate = (rate < 0.0 || rate > 1.0)
				   ? 0.0 : rate;
}

double CommissionEmployee::getRate() const
{
	return commissionRate;
}

double CommissionEmployee::earnings() const
{
	return commissionRate * grossSales;
}
void CommissionEmployee::print() const
{
	cout << "commission employee: " << getFrist() << " "
		 << getLast() << "\nSSN: " << getSSN()
		 << "\ngross sales: " << getSales()
		 << "\ncommission rate: " << getRate();
}
