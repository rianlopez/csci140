/* Program: TimeAppRev.cpp
   Author: Rian Lopez
   Class: CSCI 140 MW
   Date: 4/27/19
   Description: A driver to test class Time

   I certify that the code below is my own work.

       Exception(s): N/A
*/

#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
	Time t;

	cout << "Author: Rian Lopez\n";

	t.print();
	t.back();
	t.print();

	cout << t.minSinceMidnight() << " minutes since midnight" << endl
		<< t.minUntilMidnight() << " minutes until midnight" << endl;

	t.advance();
	t.print();

	cout << t.minSinceMidnight() << " minutes since midnight" << endl
		<< t.minUntilMidnight() << " minutes until midnight" << endl;

	// Extra credit
	t.advance();
	t.advance(15).back();
	t.print();
	t.advance(150);
	t.print();

	return 0;
}