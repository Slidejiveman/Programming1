#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream inputFile;
	string name;
	int sales;
	int numberOfStars;

	inputFile.open("Text.txt");

	while (inputFile >> name && inputFile >> sales)
	{
		numberOfStars = sales / 100;
		cout << right << setw(10) << name;
		for (int counter = 1; counter <= numberOfStars; counter++)
			cout << "*";
		cout << endl;
	}

	return 0;
}