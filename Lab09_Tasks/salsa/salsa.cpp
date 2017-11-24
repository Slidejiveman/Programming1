#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;

void askForJars(string[], int[], int);
void generateReport(string[], int[], int);

int main()
{
	string salsaNames[SIZE] = { "mild", "medium", "sweet", "hot", "zesty" };
	int jarsSold[SIZE];

	askForJars(salsaNames, jarsSold, SIZE);
	generateReport(salsaNames, jarsSold, SIZE);

	return 0;
}

void askForJars(string salsaNames[], int jarsSold[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "How many " << salsaNames[i] << " jars were sold?\n";
		cin >> jarsSold[i];//same index links these arrays
		while (jarsSold[i] < 0)
		{
			cout << "This program will only accept non-negative values. Try again.\n";
			cin >> jarsSold[i];
		}
	}
	
}

void generateReport(string salsaNames[], int jarsSold[], int SIZE)
{
	int totalSales = 0;
	int highestSelling = jarsSold[0];
	int lowestSelling = jarsSold[0];

	for (int i = 0; i < SIZE; i++)
	{
		cout << salsaNames[i] << ": " << jarsSold[i] << endl;
		if (jarsSold[i] < jarsSold[lowestSelling])
			lowestSelling = i;//using the lowest number as the index of the other array gives you the name
		if (jarsSold[i] > jarsSold[highestSelling])
			highestSelling = i;
		totalSales += jarsSold[i];
	}
	//display report
	
	cout << "Total Sales: " << totalSales << endl;
	cout << "The lowest selling product is " << salsaNames[lowestSelling] << endl;
	cout << "The highest selling product is " << salsaNames[highestSelling] << endl;
	
}