#include <iostream>
using namespace std;

#include "Time.h"

int main()
{
	Time t;

	t.setHour(19).setMinute(37).setSecond(21);

	t.printUniversal();

	t.setTime(13, 7, 55).printStandard();

	return 0;
}
