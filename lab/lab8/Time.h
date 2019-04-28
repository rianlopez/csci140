#ifndef TIME_H
#define TIME_H

class Time
{
public:
	Time(int h = 0, int m = 0);
	int getHour() const;
	int getMinute() const;
	void setHour(int);
	void setMinute(int);
	void print() const;
	Time &advance(int m = 1);
	int minSinceMidnight() const;
	int minUntilMidnight() const;
	void back();
private:
	int hour;
	int minute;
	int hourToMinute() const;
};

#endif