/* Program: dynamicScores.cpp
   Author: Rian Lopez
   Class: CSCI 140 MW
   Date: 4/24/19
   Description: This program reads scores into a dynamic array, find
   and print the average of the scores, and sort and print the scores
   in ascending order.

   I certify that the code below is my own work.

       Exception(s): N/A
*/

#include <iostream>

using namespace std;

void sort(double*, int);

void print(const double*, int);

int main()
{
	int size;
	double *scorePtr = nullptr;
	double sum = 0;

	cout << "Please input the number of scores" << endl;
	cin >> size;

	scorePtr = new double[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Please enter a score" << endl;
		cin >> scorePtr[i];
		sum += scorePtr[i];
	}

	cout << "The average of the scores is " << sum / size << endl;

	sort(scorePtr, size);

	cout << "Here are the scores in ascending order" << endl;
	print(scorePtr, size);

    return 0;
}

void sort(double *ptr , int n)
{
	bool swapped = false;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (ptr[j] > ptr[j + 1])
			{
				double temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
				swapped = true;
			}
		}

		if (!swapped)
			break;
	}
}

void print(const double *ptr, int n)
{
	for (int i = 0; i < n; i++)
		cout << ptr[i] << endl;
}