#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int SIZE = 50;//this may need to be changed. it might pass too much info

void sort(string[], int);
void displayNames(string[], int);

int main()
{
	string names[SIZE];
	ifstream inputFile;
	int index = 0;

	inputFile.open("names.txt");
	if (inputFile)
	{
		while (index < SIZE && inputFile >> names[index])
			index++;

		sort(names, SIZE);
		displayNames(names, SIZE);

		inputFile.close();
	}
	else
		cout << "The file did not open.";


	return 0;
}

void sort(string names[], int SIZE)
{
	string temporary;//holds value before it is sorted
	bool swap = false;

	do
	{
		for (int count = 0; count < (SIZE - 1); count++)
		{
			if (names[count] >  names[count + 1])
			{
				temporary = names[count];
				names[count] = names[count + 1];
				names[count + 1] = temporary;
				swap = true;
			}
		}
	} while (swap);
}

void displayNames(string names[], int SIZE)
{
	for (int count = 0; count < SIZE; count++)
		cout << names[count] << " \n";
}