#include <iostream>
using namespace std;

// this指针

class Test
{
public:
	Test(int = 0);
	void print() const;

private:
	int x;
};

Test::Test(int value)
	: x(value)
{}

void Test::print() const
{
	cout << this << endl;
	cout << "        x = " << x << endl;
	cout << "  this->x = " << this->x << endl;
	cout << "(*this).x = " << (*this).x << endl;
}

int main()
{
	Test testObject(12);

	cout << &testObject << endl;

	testObject.print();

	return 0;
}
