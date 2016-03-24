#include "Employee.h"

using namespace std;

Employee::Employee(const string &frist, const string &last, 
	const string ssn)
	: fristName(frist), lastName(last), ssNumber(ssn)
{}

Employee::~Employee()
{}

void Employee::setFrist(const string &frist)
{
	fristName = frist;
}

string Employee::getFrist() const
{
	return fristName;
}

void Employee::setLast(const string &last)
{
	lastName = last;
}

string Employee::getLast() const
{
	return lastName;
}

void Employee::setSSN(const string &ssn)
{
	ssNumber = ssn;
}

string Employee::getSSN() const
{
	return ssNumber;
}

void Employee::print() const
{
	cout << getFrist() << " " << getLast()
		 << "\nSSN: " << getSSN();
}
