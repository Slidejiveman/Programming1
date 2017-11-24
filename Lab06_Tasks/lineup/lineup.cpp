#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream inputFile;
	string name;
	string maximum;
	string minimum;

	inputFile.open("Names.txt");

	inputFile >> name;
	maximum = minimum = name;

	while (inputFile >> name)
	{
		if (name > maximum)
			maximum = name;
		if (name < minimum)
			minimum = name;
	}

	cout << "The first person in line is " << minimum << " and the last person in line is " << maximum << ".\n";
	return 0;
}