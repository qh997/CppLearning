#include <iostream>
#include <iomanip>

using namespace std;

#include "Time.h"

Time::Time(int h, int m, int s)
{
	setTime(0, 0, 0);
	setTime(h, m, s);
}

Time &Time::setTime(int h, int m, int s)
{
	setHour(h);
	setMinute(m);
	setSecond(s);

	return *this;
}

Time &Time::setHour(int h)
{
	secTotal = ((h >=0 && h < 24) ? h * 3600 : 0)
			 + secTotal % 3600;
	return *this;
}

Time &Time::setMinute(int m)
{
	secTotal = (secTotal / 3600) * 3600
			 + ((m >=0 && m < 60) ? m * 60 : 0)
			 + (secTotal % 60);
	return *this;
}

Time &Time::setSecond(int s)
{
	secTotal = (secTotal / 60) * 60
			 + ((s >=0 && s < 60) ? s : 0);
	return *this;
}

int &Time::badSetTime()
{
	return secTotal;
}

int Time::getHour() const
{
	return secTotal / 3600;
}

int Time::getMinute() const
{
	return (secTotal % 3600) / 60;
}

int Time::getSecond() const
{
	return secTotal % 60;
}


void Time::printUniversal() const
{
	cout << setfill('0')
		 << setw(2) << getHour() << ":"
		 << setw(2) << getMinute() << ":"
		 << setw(2) << getSecond()
		 << endl;
}

void Time::printStandard()
{
	cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":"
		 << setfill('0') << setw(2) << getMinute() << ":"
		 << setw(2) << getSecond() << (getHour() < 12 ? " AM" : " PM")
		 << endl;
}
