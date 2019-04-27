/* Program: memberTest.cpp
   Author: Rian Lopez
   Class: CSCI 140 MW
   Date: 4/26/19
   Description: This program tests a recursive function that determines
   if a value is a member of an array.

   I certify that the code below is my own work.

       Exception(s): N/A
*/

#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

bool isMember(const int a[], int n, int key);

int main()
{
	int arr[MAX_SIZE];
	int num;

	cout << "Author: Rian Lopez" << endl
		<< "Please enter " << MAX_SIZE << " values" << endl;

	for (int i = 0; i < MAX_SIZE; i++)
		cin >> arr[i];

	cout << "Please enter a value to search for" << endl;
	cin >> num;

	if (isMember(arr, MAX_SIZE, num))
		cout << "Found" << endl;
	else
		cout << "Not found" << endl;

	return 0;
}

bool isMember(const int a[], int n, int key)
{
	if (n == 1 && a[0] != key)
		return 0;
	if (a[n - 1] == key)
		return 1;
	return isMember(a, n - 1, key);
}