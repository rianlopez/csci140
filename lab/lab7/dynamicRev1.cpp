/* Program: dynamicRev1.cpp
   Author: Rian Lopez
   Class: CSCI 140 MW
   Date: 4/17/19
   Description: This program demonstrates the use of dynamic variables

   I certify that the code below is my own work.

       Exception: dynamic.cpp
*/

#include <iostream>
using namespace std;

const int MAXNAME = 10;

int main()

{
	int pos;
	char * name;
	int * one;
	int * two;
	int * three;
	int result;

	one = new int; // Added code to allocate the integer variable one here
	two = new int; // Added code to allocate the integer variable two here
	three = new int; // Added code to allocate the integer variable three here
	name = new char[MAXNAME]; // Added code to allocate the character array pointed by name

	cout << "Modified by: Rian Lopez\n";

	cout << "Enter your last name with exactly 10 characters." << endl;
	cout << "If your name has < 10 characters, repeat last letter. " << endl
		<< "Blanks at the end do not count." << endl;

	for (pos = 0; pos < MAXNAME; pos++)
		cin >> *(name + pos); // Added code to read a character into the name array

	cout << "Hi ";
	for (pos = 0; pos < MAXNAME; pos++)
		cout << *(name + pos); // Added code to a print a character from the name array

	cout << endl << "Enter three integer numbers separated by blanks" << endl;
	cin >> *one >> *two >> *three; // Added code to input three numbers and store them in the
								   // dynamic variables pointed to by pointers one, two, and three.

	//echo print
	cout << "The three numbers are " << endl;
	cout << *one << " " << *two << " " << *three << endl; // Added code to output those numbers

	result = *one + *two + *three; // Added code to calculate the sum of the three numbers
	cout << "The sum of the three values is " << result << endl;

	// Added code to deallocate one, two, three and name
	delete one;
	delete two;
	delete three;
	delete[] name;

	return 0;
}
