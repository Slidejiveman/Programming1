#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int SIZE = 12;
	double rainfall[SIZE];
	string months[SIZE] {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
	string highestMonth, lowestMonth;
	double highest, lowest;
	double averageRainfall;
	double totalRainfall = 0;

	//get rainfall values
	cout << "Enter twelve values of rainfall. They will be associated with the months of the year respectively.\n";
	for (int index = 0; index < SIZE; index++)
	{
		
		cin >> rainfall[index];

		if (rainfall[index] == -1)//input validation
		{
			cout << "A negative value of rainfall cannot be accepted.\n";
			exit(0);
		}
	}

	
	
	//calculate total rainfall for the year
	for (int count = 0; count < SIZE; count++)
	{
		totalRainfall += rainfall[count];
	}
	

	//calculate the average rainfall for the year

	averageRainfall = totalRainfall / static_cast<double>(SIZE);

	cout << "The total rainfall for the year is " << totalRainfall << ". \n"
		<< "The average rainfall for a month is " << averageRainfall << ". \n";

	//find highest and lowest rainfall values
	highest = rainfall[0];
	lowest = rainfall[0];

	for (int count = 1; count < SIZE; count++)
	{
		if (rainfall[count] > highest)
		{
			highest = rainfall[count];
			highestMonth = months[count];
		}
		if (rainfall[count] < lowest)
		{
			lowest = rainfall[count];
			lowestMonth = months[count];
		}
	}

	cout << lowestMonth << " had the smallest rainfall with " << lowest << " inches. \n"
		<< highestMonth << " had the largest rainfall with " << highest << " inches. \n";
	return 0;
}