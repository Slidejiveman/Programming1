#ifndef CAR_H
#define CAR_H

class Car
{
private:
	int mileage; //total mileage on the odometer
	double fuelLevel; //amount of fuel in the 12 gallon tank. 0-12 permitted
	double totalGasUsed; //keeps track of miles driven while program is running.
	double totalMPG; //holds the miles per gallon for the total trip
public:
	Car(int, double); // accepts mileage and fuel level
	void addFuel(double); //adds fuel to the car accepts gallons
	bool outOfGasCityDrive(double); //accepts trip miles, returns whether tank empties
	bool outOfGasHighwayDrive(double); //accepts trip miles, returns whether tank empties
	void showCar(); //prints car status
	//double averageTotalMPG(double, double); //calculated and returned, depends on number of miles driven where
};

#endif