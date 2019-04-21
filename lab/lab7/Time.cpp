#include "Time.h"
#include <iostream>

using namespace std;

Time::Time(int h, int m)
{
	if (h >= 0 && h < 24)
		hour = h;
	else
		hour = 0;

	if (m >= 0 && m < 60)
		minute = m;
	else
		minute = 0;
}

int Time::getHour() const
{
	return hour;
}

int Time::getMinute() const
{
	return minute;
}

void Time::setHour(int h)
{
	if (h >= 0 && h < 24)
		hour = h;
}

void Time::setMinute(int m)
{
	if (m >= 0 && m < 60)
		minute = m;
}

void Time::print() const
{
	if (hour == 0)
		cout << "12";
	else if (hour < 13)
		cout << hour;
	else
		cout << hour % 12;

	if (minute < 10)
		cout << ":0" << minute;
	else
		cout << ":" << minute;

	if (hour < 12)
		cout << " AM" << endl;
	else
		cout << " PM" << endl;
}

void Time::advance()
{
	if (minute + 1 == 60)
	{
		minute = 0;

		if (hour + 1 == 24)
			hour = 0;
		else
			hour++;
	}
	else
		minute++;
}