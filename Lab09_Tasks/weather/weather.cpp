#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int ROWS = 3;
const int COLUMNS = 30;

void fileRead(char[][COLUMNS], int);
void displayReport(char[][COLUMNS], int);

int main()
{
	char weather[ROWS][COLUMNS];

	fileRead(weather, ROWS);
	displayReport(weather, ROWS);

	return 0;
}

void fileRead(char weather[][COLUMNS], int ROWS)
{
	ifstream inputFile;

	inputFile.open("RainOrShine.dat");
	
	if (inputFile)
	{
		for (int rows = 0; rows < ROWS; rows++)
		{
			for (int columns = 0; columns < COLUMNS; columns++)
			{
				inputFile >> weather[rows][columns];
			}
		}
		inputFile.close();
	}
	else
		cout << "The file did not open.";
}

void displayReport(char weather[][COLUMNS], int ROWS)
{
	int sunnyDays;
	int sunnyDayTotal = 0;
	int rainyDays;
	int rainyDayTotal = 0;
	int cloudyDays;
	int cloudyDayTotal = 0;
	int maximumRainyIndex = 0;
	int maximumRainy = 0;
	string months[3] = { "June", "July", "August" };

	for (int c = 0; c < ROWS; c++)
	{
		sunnyDays = 0;
		rainyDays = 0;
		cloudyDays = 0;

		for (int i = 0; i < COLUMNS; i++)
		{

			if (weather[c][i] == 'S')
			{
				sunnyDays++;
				sunnyDayTotal++;
			}
			else if (weather[c][i] == 'R')
			{
				rainyDays++;
				rainyDayTotal++;
			}
			else
			{
				cloudyDays++;
				cloudyDayTotal++;
			}
		}

		if (rainyDays > maximumRainy)
		{
			maximumRainy = rainyDays;
			maximumRainyIndex = c;
		}

		cout << "In " << months[c] << " there were " 
			<< sunnyDays << " sunny days, " << cloudyDays << " cloudy days, "
			<< " and " << rainyDays << " rainy days \n";
	}

	cout << "Throughout the summer testing, there were "
		<< sunnyDayTotal << " sunny days, " << cloudyDayTotal << " cloudy days, "
		<< " and " << rainyDayTotal << " rainy days \n";

	cout << "The greatest number of rainy days occured in " << months[maximumRainyIndex] << ". " << endl;
}
