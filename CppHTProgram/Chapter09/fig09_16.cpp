#include <iostream>
using namespace std;

#include "Time.h"

int main(int argc, char **argv) {
	Time t;
	cout << "The initial universal time is ";
	t.printUniversal();
	cout << "The initial Standard time is ";
	t.printStandard();

	t.setTime(13, 27, 6);
	cout << "The universal time is ";
	t.printUniversal();
	cout << "The Standard time is ";
	t.printStandard();

	t.setTime(99, 31, 99);
	cout << "The universal time is ";
	t.printUniversal();
	cout << "The Standard time is ";
	t.printStandard();

	t.badSetTime() = 23489;
	t.printUniversal();
}