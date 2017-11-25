#include <iostream>
#include <fstream>
using namespace std;

//function prototypes
void sortArray(int[], int, ofstream&);
void selectionSort(int[], int, ofstream&);


int main()
{
	const int SIZE = 20;
	ofstream outputFile;

	outputFile.open("prgmAsn1.txt");

	//array of unsorted values
	//int values[SIZE] = { 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 5, 0 };//case 1
	//int values[SIZE] = { 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95 };//case 2
	int values[SIZE] = { 40, 70, 20, 15, 5, 65, 80, 85, 0, 95, 25, 35, 30, 60, 45, 10, 50, 55, 90, 75 };//case 3

	//perform the bubble sort
	sortArray(values, SIZE, outputFile);

	//reinitialize the array at starting values
	//int valuesCopy[SIZE] = { 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 15, 10, 5, 0 };//case 1
	//int valuesCopy[SIZE] = { 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95 };//case 2
	int valuesCopy[SIZE] = { 40, 70, 20, 15, 5, 65, 80, 85, 0, 95, 25, 35, 30, 60, 45, 10, 50, 55, 90, 75 };//case 3

	//perform the selection sort
	selectionSort(valuesCopy, SIZE, outputFile);

	outputFile.close();

	return 0;
}

void sortArray(int values[], int SIZE, ofstream &outputFile)
{
	bool swap;
	int temp;
	int items = 20;
	int comparisons = 0;
	int interchanges = 0;

	do
	{
		swap = false;
		for (int count = 0; count < (SIZE - 1); count++)
		{
			comparisons++;
			if (values[count] > values[count + 1])
			{
				temp = values[count];
				values[count] = values[count + 1];
				values[count + 1] = temp;
				swap = true;
				interchanges++;
			}
		}

	} while (swap);

	cout << "Case 3 \n"//case number is hard-coded based on which iteration of the data
		 << "Algorithm \t N \t Exchanges \t Comparisons\n"
		 << "Bubble Sort\t" << items << "\t    " << interchanges << "\t\t    " << comparisons << endl;

	outputFile << "Case 3 \n"//case number hard-coded here as well
		<< "Algorithm \t N \t Exchanges \t Comparisons\n"
		<< "Bubble Sort\t" << items << "\t    " << interchanges << "\t\t    " << comparisons << endl;
}

void selectionSort(int valuesCopy[], int SIZE, ofstream &outputFile)
{
	int startScan, minIndex, minValue;
	int items = 20;
	int comparisons = 0;
	int interchanges = 0;

	for (startScan = 0; startScan < (SIZE - 1); startScan++)
	{
		minIndex = startScan; 
		minValue = valuesCopy[startScan];
		for (int index = startScan + 1; index < SIZE; index++)
		{
			comparisons++;
			if (valuesCopy[index] < minValue)
			{
				minValue = valuesCopy[index];
				minIndex = index;
				interchanges++;
			}
		}
		valuesCopy[minIndex] = valuesCopy[startScan];
		valuesCopy[startScan] = minValue;
	}
	cout << "Selection Sort\t" << items << "\t    " << interchanges << "\t\t    " << comparisons << endl;
	outputFile << "Selection Sort\t" << items << "\t    " << interchanges << "\t\t    " << comparisons << endl;
}