#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int points; //entered by the user
	int total = 0; //holds running total
	int period = 1; //counter
	int maximum = 0; //to hold maximum values as they are entered
	int minimum = 1000; //to hold minimum values as they are entered
	float average; //to hold the average of the total divided by the period

	cout << "You may enter values of experience points gained in a play period." << endl;
	cout << "This program will return the number of points\n";
	cout << "gained throughout your character's life. Enter -1 when finished." << endl;

	cout << "Enter experience points gained in period " << period << ": " << endl;
	cin >> points;

	while (points != -1)
	{
		total += points;
		if (points > maximum )
			maximum = points;
		if (points < minimum)
			minimum = points;
		period++;
		cout << "Enter experience points gained in period " << period << ": " << endl;
		cin >> points;
	}
	cout << "Your total points are " << total << ". " << endl;

	//calculate average points per session
	average = static_cast<float>(total) / (period-1);
	
	cout << fixed << showpoint << setprecision(2);
	cout << "Your average points per play period are " << average << ".\n";
	cout << "Your maximum points in one play period are " << maximum << ".\n";
	cout << "Your minimum points in one play period are " << minimum << ".\n";

	return 0;
}