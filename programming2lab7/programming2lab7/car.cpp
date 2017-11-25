#include "car.h"
#include <iostream>
#include <fstream>

using namespace std;


//alternate constructor. There is no default. Used to set odometer and gas in tank
Car::Car(int initialMileage, double startingFuel)
{
	//collect odometer and initialize values
	mileage = initialMileage;
	totalGasUsed = 0; //must be zero to prevent display errors
	totalMPG = 0;//must be zero to prevent display errors

	//collect starting fuel level
	do
	{
		if (startingFuel >= 0 && startingFuel <= 12)
		{
			fuelLevel = startingFuel;
		}
		else
			cout << "Fuel levels are only permitted between 0 and 12\n";
	}
	while (fuelLevel < 0 || fuelLevel > 12); //input validation
}

//adds fuel to the gas tank. Acceptabel levels are 0 - 12
void Car::addFuel(double addedFuel)
{
	//add the new fuel to the old fuel amount if there is space in tank
	if (fuelLevel + addedFuel < 12)
	{
		fuelLevel = fuelLevel + addedFuel;
		cout << "Fuel successfully added\n";
	}
	else if (fuelLevel + addedFuel > 12)
	{
		fuelLevel = (addedFuel - fuelLevel); //find allowable fuel increase
		cout << "Fuel added, but only " << fuelLevel << " would fit\n";
		fuelLevel += addedFuel; //add fuel to capacity
	}

}

//checks to see if car ran out of gas in the city
bool Car::outOfGasCityDrive(double milesDriven)
{
	bool outOfGas = false; //bool returned to main
	double gasUsed; //gas used based on miles per gallon * miles driven
	double cityMPG = 16.5; //these values do not changes
	
	//add miles driven to the total mileage
	mileage += milesDriven;
	
	//calculate whether or not the car is out of gas
	gasUsed = milesDriven / cityMPG;
	
	//keep track of total gas used
	totalGasUsed += gasUsed;

	//adjust fuel level
	fuelLevel -= gasUsed;

	//test to see if car is out of gas
	if (fuelLevel < gasUsed)
	{
		outOfGas = true;
		fuelLevel = 0;
		cout << "The car has run out of gas.\n";
	}

	return outOfGas;
}

//duplicates the above function with highwayMPG rather than cityMPG
bool Car::outOfGasHighwayDrive(double milesDriven)
{
	bool outOfGas = false; //bool returned to main
	double gasUsed; //gas used based on miles per gallon * miles driven
	double highwayMPG = 24.3; //these values do not change

	//add miles driven to the total mileage
	mileage += milesDriven;
	
	//calculate whether or not the car is out of gas
	gasUsed = milesDriven / highwayMPG;
	
	//keep track of gas used
	totalGasUsed += gasUsed;

	//adjust fuel level
	fuelLevel -= gasUsed;

	//test to see if car has run out of gas
	if (fuelLevel < gasUsed)
	{
		outOfGas = true;
		fuelLevel = 0;
		cout << "The car has run out of gas.\n";
	}
	return outOfGas;
}

//displays car status
void Car::showCar()
{
	ofstream outputFile("lab7Output.txt", ios::app); //for printable output

	//check file open
	if (outputFile.fail())
	{
		cout << "the outputFile did not open!\n";
		return;
	}
	
	//calculate the total MPG and prevent division by 0
	if (totalGasUsed > 0)
		totalMPG = static_cast<double>(mileage) / totalGasUsed;
	else
		totalMPG = 0;

	//display and write to file
	cout << endl << "Fuel left in tank: " << fuelLevel << endl
		<< "Mileage: " << mileage << endl
		<< "Average MPG in city : 16.5" << endl
		<< "Average MPG on highway: 24.3" << endl
		<< "Average total MPG: " << totalMPG << endl << endl;

	outputFile << endl << "Fuel left in tank: " << fuelLevel << endl
		<< "Mileage: " << mileage << endl
		<< "Average MPG in city : 16.5" << endl
		<< "Average MPG on highway: 24.3" << endl
		<< "Average total MPG: " << totalMPG << endl << endl;

	//close outputFile
	outputFile.close();
}