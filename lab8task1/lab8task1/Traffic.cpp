#include "traffic.h"
#include <iostream>
#include <fstream>
using namespace std;

// The Enter function simulates entry of people/cars into
// the park and displays a warning if capacity is exceeded.
// Parameters:
// Cars represents the number of cars entering the park.
// People represents the number of people entering the park.

//constants
const int MAX_CARS = 10000;   //optimal number of cars in park
const int MAX_PEOPLE = 30000; //optimal number of people in park

//function simulating the entrance of people and cars into the park
void Traffic::enter(int cars, int people)
{
	ofstream enterOutput("lab8Output.txt", ios::app);
	carsInPark += cars;
	peopleInPark += people;

	//block displays when the people have exceeded the park's threshold
	if ((carsInPark > MAX_CARS) || (peopleInPark > MAX_PEOPLE))
	{
		cout << "***Warning, park capacity exceeded!***" << endl << endl;
		enterOutput << "***Warning, park capacity exceeded!***" << endl << endl;
		display();
	}
	enterOutput.close();
}

// Define other functions below

//default constructor of the object, initializes to zero
Traffic::Traffic()
{
	carsInPark = 0;
	peopleInPark = 0;
}

//displays current number of people and cars in the park
void Traffic::display()
{
	ofstream displayOutput("lab8Output.txt", ios::app);
	cout << "The number of cars in the park is: " << carsInPark << endl;
	cout << "The number of people in the park is: " << peopleInPark << endl
		<< endl << endl;
	displayOutput << "The number of cars in the park is: " << carsInPark << endl;
	displayOutput << "The number of people in the park is: " << peopleInPark << endl
		<< endl << endl;
	displayOutput.close();
}

//function simulating the departure of people and cars from the park
void Traffic::exit(int cars, int people)
{
	ofstream exitOutput("lab8Output.txt", ios::app);
	bool carsIsFull = false; // bool assumes that park is not full
	bool peopleIsFull = false;
	bool carsSwitched = false; //bool determines whether or not threshold has been crossed
	bool peopleSwitched = false;
		
	//check whether or not park is full
	if (carsInPark > MAX_CARS)
	{
		carsIsFull = true;
	}
	if (peopleInPark > MAX_PEOPLE)
	{
		peopleIsFull = true;
	}

	carsInPark -= cars;
	peopleInPark -= people;

	if (carsInPark < MAX_CARS && carsIsFull)
		carsSwitched = true;
	if (peopleInPark < MAX_PEOPLE && peopleIsFull)
		peopleSwitched = true;

	//block that displays when the number of people has decremented below the park's threshold.
	//tests against whether the threshold was crossed and which threshold it was
	if (peopleInPark < MAX_PEOPLE && peopleSwitched)
	{
		cout << "***Notice: There are now less than 30,000 people in the park.***" << endl
			<< endl;
		exitOutput << "***Notice: There are now less than 30,000 people in the park.***" << endl
			 << endl;
	}
	if (carsInPark < MAX_CARS && carsSwitched)
	{
		cout << "***Notice: There are now less than 10,000 cars in the park.***" << endl
			<< endl;
		exitOutput << "***Notice: There are now less than 10,000 cars in the park.***" << endl
			<< endl;
	}

	//call display function to show current totals
	if (carsSwitched || peopleSwitched)
		display();

	exitOutput.close();
}