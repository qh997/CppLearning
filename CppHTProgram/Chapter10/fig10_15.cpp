#include <iostream>
using namespace std;

//友元函数

class Count {
	friend void setX(Count &, int);

public:
	Count() : x(0) {}

	void print() const {
		cout << x << endl;
	}

private:
	int x;
};

void setX(Count &c, int val) {
	c.x = val;
}

int main() {
	Count counter;

	counter.print();

	setX(counter, 8);

	counter.print();

	return 0;
}
