#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 10;
	int values[SIZE];
	int largest, smallest;

	cout << "Enter 10 values to be stored in the array.\n";
	
	for (int count = 0; count < SIZE; count++)
		cin >> values[count];

	largest = values[0];
	smallest = values[0];
	for (int count = 1; count < SIZE; count++)
	{
		if (values[count] > largest)
			largest = values[count];
		if (values[count] < smallest)
			smallest = values[count];
	}

	cout << "The smallest value is " << smallest << " and the largest is " << largest << ".\n";

	return 0;
}