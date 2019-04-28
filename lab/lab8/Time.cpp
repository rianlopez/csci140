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

Time& Time::advance(int m)
{
	if (m < 1)
		m = 1;

	if (minute + m >= 60)
	{
		if ((minute + m) / 60 + hour >= 24)
			hour = ((minute + m) / 60 + hour) % 24;
		else
			hour = (minute + m) / 60 + hour;

		minute = (minute + m) % 60;
	}
	else
		minute += m;

	return *this;
}

int Time::minSinceMidnight() const
{
	return hourToMinute() + minute;
}

int Time::minUntilMidnight() const
{
	return 1440 - hourToMinute() - minute;
}

void Time::back()
{
	if (minute == 0)
	{
		minute = 59;

		if (hour == 0)
			hour = 23;
		else
			hour--;
	}
	else
		minute--;
}

int Time::hourToMinute() const
{
	return hour * 60;
}