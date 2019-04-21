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
	void advance();
private:
	int hour;
	int minute;
};

#endif