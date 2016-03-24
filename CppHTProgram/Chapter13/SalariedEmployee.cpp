#include "SalariedEmployee.h"

using namespace std;

SalariedEmployee::SalariedEmployee(const string &frist, const string &last, 
	const string ssn, double salary)
	: Employee(frist, last, ssn)
{
	setWeeklySalary(salary);
}

SalariedEmployee::~SalariedEmployee()
{}

void SalariedEmployee::setWeeklySalary(double salary)
{
	weeklySalary = (salary < 0.0) ? 0.0 : salary;
}

double SalariedEmployee::getWeeklySalary() const
{
	return weeklySalary;
}

double SalariedEmployee::earnings() const
{
	return getWeeklySalary();
}

void SalariedEmployee::print() const
{
	cout << "salaried employee: ";
	Employee::print();
	cout << "\nweekly salary: " << weeklySalary;
}
