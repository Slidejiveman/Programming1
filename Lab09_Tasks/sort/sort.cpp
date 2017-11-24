#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int SIZE = 50;

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
		
		sort(names, index);
		displayNames(names, index);

		inputFile.close();
	}
	else
		cout << "The file did not open.\n";


	return 0;
}

void sort(string names[], int size)
{
	string temporary;//holds value before it is sorted
	bool swap; //= false;

	do//swap is a do-while that requires a bool and a temporary variable of a data type
	{
		swap = false;//make sure to set this false here
		for (int count = 0; count < (size - 1); count++)//size - 1 because can't swap off end of array
		{
			if (names[count] >  names[count + 1])
			{
				
				temporary = names[count];//change temporary, count, then count+1 in that order
				names[count] = names[count + 1];
				names[count + 1] = temporary;
				swap = true;
			}
		}
	} while (swap);//fall out of the loop whenever a swap does not take place.
}

void displayNames(string names[], int size)
{
	for (int count = 0; count < size; count++)
		cout << names[count] << " \n";
}