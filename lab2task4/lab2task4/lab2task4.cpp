#include<iostream>
#include<iomanip>
#include<fstream>


//LAB TASK 4

using namespace std;

//function prototypes
void sortTests(int*, int);
double findAverage(int*, int);

int main()
{
	int numTests;//holds array size entered by user
	int *scorePtr = nullptr;//pointer to be used as an array
	double averageScore;//holds return value from findAverage
	ofstream outputFile;//to print output from wordpad

	//open outputFile
	outputFile.open("labTask4.txt");

	//begin setting up output
	outputFile << "OUTPUT -- LAB TASK 4 \n\n";

	//prompt for array size
	cout << "Enter a number of test scores to be sorted. \n";
	cin >> numTests;

	//create dynamically allocated memory
	scorePtr = new int[numTests];

	//collect scores to average
	cout << "Next, please enter the scores to be averaged.\n";
	for (int i = 0; i < numTests; i++)//since size of array is known, counter controlled
		cin >> *(scorePtr + i); 

	//sort tests by score, large to small
	sortTests(scorePtr, numTests);

	//find average of the scores
	averageScore = findAverage(scorePtr, numTests);

	//display and output data
	cout << endl << setw(8) << "Scores: " << endl << endl;
	outputFile << endl << setw(8) << "Scores: " << endl << endl;
	for (int i = 0; i < numTests; i++)
	{
		cout << *(scorePtr + i) << endl;
		outputFile << *(scorePtr + i) << endl;
	}
	cout << endl << setw(8) << "Average: " << endl << averageScore << endl << endl;
	outputFile << endl << setw(8) << "Average: " << endl << averageScore << endl << endl;

	//free up memory and reestablish nullptr
	delete scorePtr;
	scorePtr = nullptr;

	//close outputFile
	outputFile.close();
}

void sortTests(int* scorePtr, int numTests)
{
	bool swap;
	int temp;

	do
	{
		swap = false;
		for (int count = 0; count < (numTests - 1); count++)
		{
			if (*(scorePtr + count) < *(scorePtr + (count + 1)))//sorting largest to smallest
			{
				temp = *(scorePtr + count);
				*(scorePtr + count) = *(scorePtr + (count + 1));
				*(scorePtr + (count + 1)) = temp;
				swap = true;
			}
		}

	} while (swap);
}

double findAverage(int* scorePtr, int numTests)
{
	int totalPoints = 0;//accumulator
	double averageScore;//return value

	for (int count = 0; count < numTests; count++)
	{
		totalPoints += *(scorePtr + count);
		averageScore = totalPoints / static_cast<double>(numTests);
	}
	return averageScore;
}