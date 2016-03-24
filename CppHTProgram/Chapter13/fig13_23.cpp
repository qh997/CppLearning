#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using namespace std;

void virtualViaRef(const Employee &baseClassRef);
void virtualViaPtr(const Employee *const baseClassPtr);

#define SHOW(X) \
do { \
	cout << #X" = " << (X) << endl; \
} while(0)

int main()
{
	cout << fixed << setprecision(2);

	SalariedEmployee se(
		"John", "Smith", "111-11-111", 800);
	SalariedEmployee se1(
		"John1", "Smit1", "111-11-1111", 801);
	SalariedEmployee se2(
		"John2", "Smit2", "111-11-2222", 802);
	HourlyEmployee he(
		"Karen", "Price", "222-22-222", 16.75, 40);
	CommissionEmployee ce(
		"Sue", "Jones", "333-33-333", 10000, .06);
	BasePlusCommissionEmployee bpce(
		"Bob", "Lewis", "444-44-444", 5000, .04, 300);

	vector<Employee *> employees(4);
	employees[0] = &se;
	employees[1] = &he;
	employees[2] = &ce;
	employees[3] = &bpce;

	for (size_t i = 0; i < employees.size(); i++)
	{
		virtualViaPtr(employees[i]);
	}

	cout << "\n======================\n" << endl;

	for (size_t i = 0; i < employees.size(); i++)
	{
		virtualViaRef(*employees[i]);
	}

	SHOW(sizeof(void *));
	SHOW(sizeof(long));
	SHOW((void *)&se1); // 对象中存放虚函数表地址的地址（位于对象的首地址）
	SHOW((void *)&se2);
	SHOW((void *)*(void **)&se1); // 虚函数表的地址
	SHOW((void *)*(void **)&se2); // 同一类的对象指向同一个虚函数表
	SHOW((void *)*(void **)*(void ***)&se1); // 第一个虚函数的地址（虚函数表第一项的内容）
	SHOW((void *)*(void **)*(void ***)&se2);
	SHOW((void *)*((void **)*(void ***)&se1 + 1)); // 第二个虚函数的地址
	SHOW((void *)*((void **)*(void ***)&se2 + 1));

	cout << "\n++++++++++++++++++++++++++" << endl;
	double (*func)(Employee *) = (double (*)(Employee *))*((void  **)*(void ***)&se1 + 1); // 直接使用虚函数表调用virtual函数
	func(&se1);
	cout << "\n++++++++++++++++++++++++++" << endl;
	(*(double (*)(Employee *))*((long *)*(long *)&se1 + 1))(&se2);
}

void virtualViaPtr(const Employee *const baseClassPtr)
{
	baseClassPtr->print();
	cout << endl;
	SHOW(baseClassPtr->earnings());
	cout << "\n" << endl;
}

void virtualViaRef(const Employee &baseClassRef)
{
	baseClassRef.print();
	cout << endl;
	SHOW(baseClassRef.earnings());
	cout << "\n" << endl;
}
