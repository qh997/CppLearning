#include "HourlyEmployee.h"

using namespace std;

HourlyEmployee::HourlyEmployee(const string &frist, const string &last, 
	const string ssn, double hourlyWage, double hoursWorked)
	: Employee(frist, last, ssn)
{
	setWage(hourlyWage);
	setHours(hoursWorked);
}

HourlyEmployee::~HourlyEmployee()
{}

void HourlyEmployee::setWage(double hourlyWage)
{
	wage = (hourlyWage < 0.0) ? 0.0 : hourlyWage;
}

double HourlyEmployee::getWage() const
{
	return wage;
}

void HourlyEmployee::setHours(double hoursWorked)
{
	hours = (hoursWorked < 0.0 || hoursWorked >= 168.0)
		  ? 0.0 : hoursWorked;
}

double HourlyEmployee::getHours() const
{
	return hours;
}

double HourlyEmployee::earnings() const
{
	if (getHours() <= 40)
	{
		return getWage() * getHours();
	}
	else
	{
		return 40 * getWage() + ((getHours() - 40) * getWage() * 1.5);
	}
}

void HourlyEmployee::print() const
{
	cout << "hourly employee: ";
	Employee::print();
	cout << "\nhourly wage: " << getWage()
		 << "\nhourly worked: " << getHours();
}
