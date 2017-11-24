

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//This program finds the cost of a purchase including sales tax.
	const float TAXRATE = .075;
	int cost;
	float total;
	int roundTotal;
	int change, quarters, dimes, nickels, pennies;

	cout << "What is the cost of your item? ";
	cin >> cost;

	//Calculate the amount of tax owed.
	total = (cost * TAXRATE) + cost;

	roundTotal = static_cast<int>(total + .5);
	
	cout << fixed << showpoint << setprecision(1);
	cout << "The total amount due is " << roundTotal << ". \n\n";

	//Calculate change
	change = 100 - roundTotal;

	//Calculate the number of Quaters to be returned.

	int initialChange = 100 - roundTotal;

	quarters = change / 25;
	change = change % 25;
	dimes = change / 10;
	change = change % 10;
	nickels = change / 5;
	change = change % 5;
	pennies = change / 1;

	cout << "Your change is " << initialChange << ", which is to be returned in " << endl;
	cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << endl;
	cout << " and " << pennies << " pennies.";

	
	return 0;
}
