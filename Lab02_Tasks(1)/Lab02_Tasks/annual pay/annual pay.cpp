#include <iostream>
using namespace std;

int main()
{
	
	float payAmount, annualPay;
	int   payPeriods;

	// replace these assignment statements with prompt/input statements
	// to ask the user for these values.
	cout << "How much do you earn in a pay period? ";
	cin >> payAmount;

	cout << "How many pay periods do you have in a year? ";
	cin >> payPeriods;
	
	annualPay = payAmount * payPeriods;

	cout << "Your annual pay is: " << annualPay << endl;

	return 0;
}
