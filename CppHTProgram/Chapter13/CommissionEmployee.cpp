#include "CommissionEmployee.h"

using namespace std;

CommissionEmployee::CommissionEmployee(const string &frist, const string &last, 
	const string ssn, double sales, double rate)
	: Employee(frist, last, ssn)
{
	setSales(sales);
	setRate(rate);
}

CommissionEmployee::~CommissionEmployee()
{}

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
	cout << "commission employee: ";
	Employee::print();
	cout << "\ngross sales: " << getSales()
		 << "\ncommission rate: " << getRate();
}
