/* Program: vendingmachine.cpp
   Author: Rian Lopez
   Class: CSCI 140 MW
   Date: 3/19/19
   Description: This program functions like a vending machine that only
   accepts one dollar bills and returns changes in quarters, dimes, and nickels.
   The number of each coin is specified by the user at the beginning of the
   program, and the user inputs a value that is a multiple of 5 to simulate
   a purchase. The program prioritizes in returning the coins with the highest
   denomination, but it can also handle special cases. Lastly, the program
   validates the user's input and loops until the user enter the sentinel value.

   I certify that the code below is my own work.

       Exception: testMakeChanges.cpp
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int DOLLAR = 100;
const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;
// in cents

struct Coin  // Coin consists of quarters, dimes, and nickels 
{
	int q, d, n;
};

void fillMachine(Coin&);
// prompts the user to input the initial amount of each coin in the machine

bool makeChanges(int amount, Coin &machine, Coin &back);
// amount – change amount to give back
// machine – current quarters, dimes, and nickels in machine     
// back – quarters, dimes, and nickels to give back     
// return true for sufficient changes; return false otherwise 

int makeTransactions(Coin &machine, Coin &back);
// return the number of valid transactions

void printReport(int, Coin);
// prints the number of valid transactions, the number of dollars, quarters,
// dimes, and nickels in the machine, and the machine balance

int main()
{
	Coin machine, change;
	
	cout << "Vending Machine Version 1B by Rian Lopez" << endl;

	fillMachine(machine);

	int transactions = makeTransactions(machine, change);

	printReport(transactions, machine);

	return 0;
}

void fillMachine(Coin &machine)
{
	int q, d, n;
	double balance;

	cout << "Fill up machine with changes. Please wait ..." << endl
		<< "Enter number of quarters, dimes, and nickels --> ";
	cin >> q >> d >> n;

	machine.q = q;
	machine.d = d;
	machine.n = n;

	balance = (q * 0.25) + (d * 0.1) + (n * 0.05);

	cout << "There are " << q << " quarters, " << d << " dimes, and " << n << " nickels." << endl
		<< "Initial machine balance is $" << fixed << showpoint << setprecision(2) << balance << "." << endl
		<< "Only one-dollar bill will be accepted." << endl
		<< "Only amount between 0 to 100 and multiple of 5 is accepted." << endl
		<< "Enter 0 to stop the program." << endl
		<< "Machine is now ready.\n" << endl;
}

bool makeChanges(int amount, Coin &machine, Coin &back)
{
	bool valid = true;

	int currentAmount = 0;
	back.q = 0;
	back.d = 0;
	back.n = 0;

	
	while (currentAmount + QUARTER <= amount && back.q != machine.q)
	{
		currentAmount += QUARTER;
		back.q++;
	}

	if (currentAmount != amount)
	{
		while (currentAmount + DIME <= amount && back.d != machine.d)
		{
			currentAmount += DIME;
			back.d++;
		}
	}

	if (currentAmount != amount)
	{
		while (currentAmount + NICKEL <= amount && back.n != machine.n)
		{
			currentAmount += NICKEL;
			back.n++;
		}
	}
	

	if (currentAmount != amount && amount % 10 != 0) // for special cases
	{
		currentAmount = 0;
		back.q = 0;
		back.d = 0;
		back.n = 0;

		if (currentAmount + QUARTER < amount && back.q != machine.q)
		{
			currentAmount += QUARTER;
			back.q++;
		}
		
		if (back.q != machine.q)
		{
			while (currentAmount + 2 * QUARTER < amount && back.q + 2 <= machine.q)
			{
				currentAmount += 2 * QUARTER;
				back.q += 2;
			}
		}

		while (currentAmount + DIME <= amount && back.d != machine.d)
		{
			currentAmount += DIME;
			back.d++;
		}

		if (currentAmount != amount)
		{
			while (currentAmount + NICKEL <= amount && back.n != machine.n)
			{
				currentAmount += NICKEL;
				back.n++;
			}
		}
	}

	if (currentAmount != amount)
		valid = false;
	else
	{
		machine.q -= back.q;
		machine.d -= back.d;
		machine.n -= back.n;
	}

	return valid;
}

int makeTransactions(Coin &machine, Coin &back)
{
	int validTransactions = 0;
	int input;

	do
	{
		cout << "Enter a purchase amount [0 - 100] --> ";
		cin >> input;

		if (input != 0)
			cout << "You entered a purchase amount of " << input << " cents." << endl;

		if (input < 0 || input > 100)
		{
			cout << "Invalid amount (outside valid range). Try again.\n" << endl;
		}
		else if (input % 5 != 0)
		{
			cout << "Invalid amount (not a multiple 5). Try again.\n" << endl;
		}
		else if (input != 0)
		{
			bool valid;
			int changeAmount;

			cout << "Please insert one-dollar bill." << endl
				<< "Processing your purchase ..." << endl;

			changeAmount = DOLLAR - input;

			valid = makeChanges(changeAmount, machine, back);

			if (valid)
			{
				cout << "Your change of " << changeAmount << " cents is given as:" << endl
					<< "    quarter(s):" << setw(2) << back.q << endl
					<< "    dime(s):" << setw(5) << back.d << endl
					<< "    nickel(s):" << setw(3) << back.n << endl << endl;

				validTransactions++;
			}
			else
			{
				cout << "Insufficient changes!" << endl
					<< "Your transaction cannot be processed." << endl
					<< "Please take back your dollar bill.\n" << endl;
			}
		}

	} while (input != 0);

	return validTransactions;
}

void printReport(int t, Coin machine)
{
	double balance = t + (machine.q * 0.25) + (machine.d * 0.1) + (machine.n * 0.05);

	cout << "Final Report is being generated ..." << endl
		<< "There are " << t << " valid transactions." << endl
		<< "Number of dollars : " << t << endl
		<< "Number of quarters: " << machine.q << endl
		<< "Number of dimes   : " << machine.d << endl
		<< "Number of nickels : " << machine.n << endl
		<< "Machine balance   : $" << fixed << showpoint << setprecision(2) << balance << endl
		<< "Machine is shutting down." << endl;
}