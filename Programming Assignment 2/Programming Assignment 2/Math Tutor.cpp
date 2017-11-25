//====================================================================
// Ryder Dale Walton
//9-26-14
//Programming Assignment #2
//Description: Math Tutor
//====================================================================

/*This program performs basic addition using random numbers
in a way conducive to pedagogy by displaying two numbers for 
the student to add. The answer is not shown until return is pressed.*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()

{
	int number1, number2; //to store random numbers to be added
	int sum; //to store the total after addition
	unsigned seed = time(0); //to hold system time and generate truer rands
	const int MIN_VALUE = 1; //to hold the lower end of random number range
	const int MAX_VALUE = 99; //to hold higher end as per instructions

	srand(seed);
	
	number1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	number2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

	cout << setw(4) << right << number1 << endl;
	cout << left << "+" << setw(3) << right << number2 << endl;
	cout << right << "____" << endl;

	cin.get();

	//calculate the sum of the two numbers
	sum = number1 + number2;

	cout << setw(4) << right << sum << endl;

	return 0;
}