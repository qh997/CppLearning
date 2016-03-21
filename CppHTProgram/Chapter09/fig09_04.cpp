#include <iostream>

using namespace std;

class Count {
public:
	void setX(int value) {
		x = value;
	}

	void print(){
		cout << x << endl;
	}

private:
	int x;
};

int main(int argc, char **argv) {
	Count counter;
	Count *counterPtr = &counter;
	Count &counterRef = counter;

	counter.setX(1);
	counter.print();

	counterPtr->setX(2);
	counterPtr->print();

	counterRef.setX(3);
	counterRef.print();

	counter.print();
}
