#include <iostream>
#include <fstream>

using namespace std;

//function prototypes
void selectionSort(int[], int);
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
	selectionSort(values, SIZE);

	//display them again.
	cout << "The sorted values are: \n";
	outputFile << "The sorted values are: \n";
	showArray(values, SIZE, outputFile);

	return 0;
}

void selectionSort(int values[], int SIZE)
{
	int startScan, minIndex, minValue;

	for (startScan = 0; startScan < (SIZE - 1); startScan++)
	{
		minIndex = startScan;
		minValue = values[startScan];
		for (int index = startScan + 1; index < SIZE; index++)
		{
			if (values[index] < minValue)
			{
				minValue = values[index];
				minIndex = index;
			}
		}
		values[minIndex] = values[startScan];
		values[startScan] = minValue;
	}
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