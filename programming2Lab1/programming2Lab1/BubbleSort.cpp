#include <iostream>
#include <fstream>

using namespace std;

//function prototypes
void sortArray(int[], int);
void showArray(const int[], int, ofstream&);

int main()
{
	const int SIZE = 6;
	ofstream outputFile;

	outputFile.open("prgmAsn1.txt");

	//array of unsorted values
	int values[SIZE] = { 7, 2, 3, 8, 9, 1 };

	//display the values
	cout << "The unsorted values are: \n";
	outputFile << "The unsorted values are: \n";
	showArray(values, SIZE, outputFile);

	//sort the values
	sortArray(values, SIZE);

	//display them again.
	cout << "The sorted values are: \n";
	outputFile << "The sorted values are: \n";
	showArray(values, SIZE, outputFile);
	
	return 0;
}

void sortArray(int values[], int SIZE)
{
	bool swap;
	int temp;

	do
	{
		swap = false;
		for (int count = 0; count < (SIZE - 1); count++)
		{
			if (values[count] > values[count + 1])
			{
				temp = values[count];
				values[count] = values[count + 1];
				values[count + 1] = temp;
				swap = true;
			}
		}

	} while (swap);
}

void showArray(const int values[], int SIZE, ofstream &outputFile)
{
	for (int count = 0; count < SIZE; count++)
	{
		cout << values[count] << " ";
		outputFile << values[count] << " ";
	}
	cout << endl;
	outputFile << endl;

}