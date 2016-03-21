#include <iostream>
using namespace std;

// 类的const成员及其初始化

class Increment {
public:
	Increment(int c = 0, int i = 1)
		: count(c), increment(i) {
	}

	void addIncrement() {
		count += increment;
	}

	void print() const {
		cout << "count = " << count
		     << ", increment = " << increment << endl;
	}

private:
	int count;
	const int increment;
};

int main() {
	Increment value(10, 5);

	cout << "Before incrementing: ";
	value.print();

	for (int j = 1; j <= 3; j++) {
		value.addIncrement();
		cout << "After incrementing: ";
		value.print();
	}

	return 0;
}
