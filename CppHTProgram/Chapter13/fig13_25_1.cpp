#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>

using namespace std;

#define SHOW(X) \
do { \
	cout << #X" = " << (X) << endl; \
} while(0)

class A
{
public:
	A(int aaa)
		: a1(aaa)
	{
		cout << "A constructor" << endl;
	}

	virtual ~A()
	{
		cout << "A destructor" << endl;
	}

	virtual int getValue()
	{
		return a1;
	}

private:
	int a1;
};

class B : public A
{
public:
	B(int aaa)
		: A(aaa)
	{
		cout << "B constructor" << endl;
	}

	virtual ~B()
	{
		cout << "B destructor" << endl;
	}

	virtual int getValue()
	{
		return A::getValue() + 999;
	}
};

int main()
{
	A *aPtr = new B(997);

	SHOW(aPtr->getValue());

	delete aPtr;
}
