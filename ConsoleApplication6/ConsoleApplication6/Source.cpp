#include<iostream>
using namespace std;

int main()

{
	int maxCredit, usedCredit, availableCredit;

	cout << "What is your maximum amount of credit?\n";
	cin >> maxCredit;

	cout << "How much credit have you used?\n";
	cin >> usedCredit;

	//Calculate remaining credit
	availableCredit = maxCredit - usedCredit;

	cout << "You have " << availableCredit << " available credit." << endl;

	return 0;
}