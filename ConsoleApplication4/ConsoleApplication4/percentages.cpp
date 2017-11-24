/* This program calculates the amount of pay that 
will be contributed to a retirement plain if
5%, 7%, or 10% of monthly pay is withheld.*/

#include<iostream>
using namespace std;

int main()

{
	//Variables to hold the monthly pay and the
	//amount of contribution
	double monthlyPay = 6000.0, contribution;

	//Calculate and display a 5% contribution
	contribution = monthlyPay * 0.05;
	cout << "5% is $" << contribution << " per month.\n";

	//7%
	contribution = monthlyPay * 0.07;
	cout << "7% is $" << contribution << " per month.\n";

	//10%
	contribution = monthlyPay * 0.1;
	cout << "10% is $" << contribution << " per month.\n";

	return 0;
}