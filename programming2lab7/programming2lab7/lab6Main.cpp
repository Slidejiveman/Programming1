#include "car.h"
#include <iostream>

using namespace std;

int main()
{
	Car myCar(0, 12); //accepts first mileage then fuelLevel
	int choice; //sentinel for do while
	double milesDriven; //holds the user choice for driving
	double addedFuel = 0; //entered by user
	bool isOutOfGas = false; //flips if the car runs out of fuel

	//create menu for user to "drive" the car
	do
	{
		cout << "Select your choice for the drive simulator:\n"
			<< "1. City Driving\n"
			<< "2. Highway Driving\n"
			<< "3. Add Fuel\n"
			<< "4. Show Car Status\n"
			<< "5. Quit\n";
		cin >> choice;

		//validate input
		if (choice < 1 || choice > 5)
		{
			cout << "Please enter a valid choice.\n";
		}

		//option 1
		if (choice == 1)
		{
			cout << "How many miles would you like to drive? \n";
			cin >> milesDriven;

			//call gas function
			isOutOfGas = myCar.outOfGasCityDrive(milesDriven);
		}

		//option 2
		if (choice == 2)
		{
			cout << "How many miles would you like to drive? \n";
			cin >> milesDriven;

			//call gas function
			isOutOfGas = myCar.outOfGasHighwayDrive(milesDriven);
		}

		//option3
		if (choice == 3)
		{
			cout << "How much fuel would you like to add? Enter between 0-12 \n";
			cin >> addedFuel;

			//call gas function
			myCar.addFuel(addedFuel);
		}

		//option4
		if (choice == 4)
		{
			//call gas function
			myCar.showCar();
		}

		//if isOutOfGas is true
		if (isOutOfGas)
		{
			myCar.showCar();
			return 0;
		}

	} while (choice != 5);

	return 0;
}