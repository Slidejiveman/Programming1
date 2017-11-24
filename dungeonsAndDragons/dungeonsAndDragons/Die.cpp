#include <cstdlib>			//rand and srand functions
#include <ctime>			//time function
#include "Die.h"

using namespace std;

//***************************************************************
// The constructor accepts an argument for the number
// of sides for the die, and performs the roll.
//***************************************************************
Die::Die(int numberSides)
{
	// Get the system time
	unsigned seed = time(0); // used to seed number gen

	// Seed random number generator
	srand(seed);

	// Set the number of sides
	sides = numberSides;

	// Perform Die roll
	roll();
}

//**************************************************************
// The roll member functions simulates a physical Die
// rolling, takes no arguments, sets value variable.
//**************************************************************
void Die::roll()
{
	// Created constant for minimum Die value
	const int NATURAL_ONE = 1; // only required here, so defined here

	// Get a random value from Die roll
	value = (rand() % (sides - NATURAL_ONE + 1)) + NATURAL_ONE;

	// To simulate the percentage die, values are rounded to multiples
	// of ten. This prevents getting bizarre numbers that are not on
	// physical dice.
	if (sides == 100)
		value = ((rand() % (10 - NATURAL_ONE + 1)) + NATURAL_ONE) * 10;
}

//**************************************************************
// The getSides member function returns the number of sides 
// assigned to the Die currently. It takes no arguments, returns
// an integer.
//**************************************************************
int Die::getSides() const
{
	return sides;
}

//**************************************************************
// The getValue member function returns the value of the last 
//roll. It takes no arguments and returns an integer.
//**************************************************************
int Die::getValue() const
{
	return value;
}