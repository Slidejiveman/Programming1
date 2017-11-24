//=====================================================
// Ryder Dale Walton
// 10-3-14
// Programming Assignment #3
// Description: Mobile Service Provider, Parts 1 -2
//=====================================================

/*This program calculates the monthly bill of a wireless
customer based on their selection of one of three packages.
Furthermore, it also calculates their monthly bill based on how many
minutes were used in a given month.*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()

{
	const double PACKAGE_A = 39.99;//used to calculate total if A is chosen
	const double PACKAGE_B = 59.99;//holds value of B, used if chosen
	const double PACKAGE_C = 69.99;//holds value of C, used if chosen
	const int CHOICE_A = 1; //entered to choose package A from menu
	const int CHOICE_B = 2; //value to choose B
	const int CHOICE_C = 3; //value to choose C
	int choice; //to hold user package selection
	int minutes; //the number of minutes used per month
	double amountDue; //total amount of package plus minutes
	double savings; //used to hold savings when comparing plans.

	cout << "Mobile Service Menu\n";
	cout << "Please select your package by entering either 1, 2, or 3.\n\n";
	cout << "1. Package A: $39.99 per month for 450 minutes. $0.45 for additional.\n";
	cout << "2. Package B: $59.99 per month for 900 minutes. $0.40 for additional.\n";
	cout << "3. Package C: $69.99 per month for unlimited minutes.\n";
	cin >> choice;

	cout << fixed << showpoint << setprecision(2);

	if (choice == CHOICE_A)
	{
		cout << "Please input the number of minutes used this month\n";
		cin >> minutes;
		if (minutes <= 450)
			cout << "The amount due is " << PACKAGE_A << ". " << endl;
		else if (minutes > 450 && minutes < 495)
		{
			amountDue = PACKAGE_A + ((minutes - 450) * 0.45);
			cout << "The amount due is " << amountDue << ". " << endl;
		}
		else if (minutes >= 495 && minutes <= 516)
		{
			amountDue = PACKAGE_A + ((minutes - 450) * 0.45);
			
			//calclate savings if customer had purchased Package B
			savings = amountDue - PACKAGE_B;
			cout << "You would have saved " << savings << " if you had purchased Package B.";
		}
		else if (minutes > 516)
		{
			amountDue = PACKAGE_A + ((minutes - 450) * 0.45);

			//calculate savings if customer had purchased Package C
			savings = amountDue - PACKAGE_C;
			cout << "You would have saved " << savings << " if you had purchased Package C.";
		}
	}
	else if (choice == CHOICE_B)
	{
		cout << "Please input the number of minutes used this month\n";
		cin >> minutes;
		if (minutes <= 900)
			cout << "The amount due is " << PACKAGE_B << ". " << endl;
		else if (minutes > 900 && minutes <= 925)
		{
			amountDue = PACKAGE_B + ((minutes - 900) * 0.40);
			cout << "The amount due is " << amountDue << ". " << endl;
		}
		else if (minutes > 925)
		{
			amountDue = PACKAGE_B + ((minutes - 900) * 0.40);
			cout << "The amount due is " << amountDue << ". " << endl;

			//calculate savings if customer had purchased Package C
			savings = amountDue - PACKAGE_C;
			cout << "You would have saved " << savings << " if you had purchased Package C.";
		}
	}
	else if (choice == CHOICE_C)
	{
		cout << "The amount due is " << PACKAGE_C << ". " << endl;
	}
	else
		cout << "Invalid input. Please run program again entering either 1, 2, or 3.";

	return 0;
}