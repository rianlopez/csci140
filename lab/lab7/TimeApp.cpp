/* Program: TimeApp.cpp
   Author: Rian Lopez
   Class: CSCI 140 MW
   Date: 4/21/19
   Description: A driver to test class Time

   I certify that the code below is my own work.

       Exception: testTimeRev.cpp
*/

#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
	Time t1;			// hour: 0, minute: 0
	Time t2(1);			// hour: 1, minute: 0
	Time t3(13, 59);	// hour: 13, minute: 59
	Time t4(23, 65);	// hour: 23, minute: 0
	Time t[3];			// Added an array of Time objects
	Time *tPtr = t;		// Added a Time pointer

	cout << "Modified by: Rian Lopez\n";

	t1.print();			// 12:00 AM
	t2.print();			// 1:00 AM
	t3.print();			// 1:59 PM (was 13:59 PM in previous version)
	t4.print();			// 11:00 PM

	t1.setHour(25);		// hour: 0, minute: 0
	t1.setMinute(-1);	// hour: 0, minute: 0
	cout << "hour: " << t1.getHour() << ", minute: " << t1.getMinute() << endl;
	// output "hour: 0, minute: 0"

	t3.advance();		// hour: 14, minute: 0
	t3.print();			// 2:00 PM
	cout << "hour: " << t3.getHour() << ", minute: " << t3.getMinute() << endl;
	// output "hour: 14, minute: 0"

	t4.setMinute(59);	// hour: 23, minute: 59
	t4.advance();		// hour: 0, minute: 0, missing in previous version
	t4.print();			// 12:00 AM

	tPtr->setHour(1);
	tPtr++;
	tPtr->setMinute(59);

	for (int i = 0; i < 3; i++)
	{
		tPtr = t + i;
		tPtr->print();
	}

	return 0;
}