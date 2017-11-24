#include <iostream>
using namespace std;

int smallValue(int[], int);
int largeValue(int[], int);

int main()
{
	const int SIZE = 10;
	int values[SIZE];
	int largest, smallest;

	cout << "Enter 10 values to be stored in the array.\n";

	for (int count = 0; count < SIZE; count++)
		cin >> values[count];

	smallest = smallValue(values, SIZE);
	largest = largeValue(values, SIZE);

	cout << "The smallest value is " << smallest << " and the largest is " << largest << ".\n";

	return 0;
}

int smallValue(int values[], const int SIZE)
{
	int smallest = values[0];
	for (int count = 1; count < SIZE; count++)
	{
		if (values[count] < smallest)
			smallest = values[count];
	}
	return smallest;
}

int largeValue(int values[], const int SIZE)
{
	int largest = values[0];
	for (int count = 1; count < SIZE; count++)
	{
		if (values[count] > largest)
			largest = values[count];
	}
	return largest;
}