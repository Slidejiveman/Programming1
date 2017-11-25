#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;//global constant, which is allowed. Global variables cause more bugs.

int linearSearch(int[], int, int);//function prototype

int main()
{
	int searchable[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//1D array initialization
	int searchObject;

	searchObject = (linearSearch, SIZE, 5);//actual parameters (arguments)

	if (searchObject != -1)
		cout << searchObject << endl;
	else
		cout << "The value is not in the array.\n";

	return 0;
}

int linearSearch(int searchable[], int SIZE, int searchValue)//formal parameters
{
	bool found = false;//flag that determines whether or not the value has been found
	int position = -1;//either the location of the index, or a value that could not be an location
	int index = 0;//counter

	while (found == false && index < SIZE)//could also say !found
	{
		if (searchable[index] == searchValue)//searchvalue found in an array
		{
			found = true;//set to true
			position = index;//location is current iteration of the loop
		}

		index++;
	}

	return position;
}