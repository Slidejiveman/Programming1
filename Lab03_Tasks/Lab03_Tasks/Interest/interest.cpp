
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	// This program calculates interest earned over the course of a given time.

	float principal;
	float rate;
	int timesCompound;
	float amount;
	float interest;

	cout << "What is the principal of your investment?\n";
	cin >> principal;

	cout << "How about the interest rate?\n";
	cin >> rate;

	cout << "how often is it compounded?\n";
	cin >> timesCompound;

	// Calculate the interest
	interest = principal * pow(1 + (rate / timesCompound), timesCompound);

	// Calculate amount in savings
	amount = interest + principal;

	cout << left << setw(20) << "Interest Rate: " << right << setw(26) << rate * 100 << "%" << endl;
	cout << left << setw(20) << "Times Compounded: " << right << setw(27) << timesCompound << endl;
	cout << left << setw(20) << "Principal: " << right << setw(20) << "$ " << fixed << showpoint << setprecision(2) << principal << endl;
	cout << left << setw(20) << "Interest: " << right << setw(20) << "$ "<< interest << endl;
	cout << left << setw(20) << "Amount in Savings: " << right << setw(20) << "$ " << amount << endl;

	return 0;
}
