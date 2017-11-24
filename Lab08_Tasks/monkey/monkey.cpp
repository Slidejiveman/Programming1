#include <iostream>
using namespace std;

const int NUM_MONKEYS = 3;
const int WORKDAYS = 5;

double averageAmountEaten(double[][WORKDAYS], int);
double leastAmountEaten(double[][WORKDAYS], int);
double mostAmountEaten(double[][WORKDAYS], int);

int main()
{
	double foodEaten[NUM_MONKEYS][WORKDAYS] = { { 5, 10, 11, 12, 9 },
												{ 5, 10, 11, 12, 9 },
												{ 5, 10, 11, 12, 9 } };
	double averageEaten;
	double leastEaten;
	double mostEaten;

	averageEaten = averageAmountEaten(foodEaten, NUM_MONKEYS);
	leastEaten = leastAmountEaten(foodEaten, NUM_MONKEYS);
	mostEaten = mostAmountEaten(foodEaten, NUM_MONKEYS);

	cout << "The average amount of food eaten by all of the monkeys during the weekdays is "
		<< averageEaten << " lbs. \n The least eaten by a single monkey on any given day is "
		<< leastEaten << " lbs. \n The most eaten by a single monkey on any given day is "
		<< mostEaten << " lbs.\n";


	return 0;
}


double averageAmountEaten(double foodEaten[][WORKDAYS], int NUM_MONKEYS)
{
	int averageEaten;
	double totalEaten = 0;
	for (int row = 0; row < NUM_MONKEYS; row++)
	{
		for (int column = 0; column < WORKDAYS; column++)
			totalEaten += foodEaten[row][column];
	}
	
	averageEaten = totalEaten / static_cast<double>(NUM_MONKEYS * WORKDAYS);

	return averageEaten;
}
double leastAmountEaten(double foodEaten[][WORKDAYS], int NUM_MONKEYS)
{
	double smallest = foodEaten[0][0];
	for (int row = 0; row < NUM_MONKEYS; row++)
	{
		for (int column = 0; column < WORKDAYS; column++)
		{
			if (foodEaten[row][column] < smallest)
				smallest = foodEaten[row][column];
		}
	}
	return smallest;
}

double mostAmountEaten(double foodEaten[][WORKDAYS], int NUM_MONKEYS)
{
	double largest = foodEaten[0][0];
	for (int row = 0; row < NUM_MONKEYS; row++)
	{
		for (int column = 0; column < WORKDAYS; column++)
		{
			if (foodEaten[row][column] > largest)
				largest = foodEaten[row][column];
		}
	}
	return largest;
}