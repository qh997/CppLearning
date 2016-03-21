#ifndef TIME_H
#define TIME_H

class Time {
public:
	Time();
	void setTime(int, int, int);
	void printUniversal();
	void printStandard();

private:
	int hour;
	int minute;
	int second;
};

#endif
