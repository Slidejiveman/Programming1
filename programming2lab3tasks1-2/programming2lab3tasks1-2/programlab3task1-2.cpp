#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	int listsize;   // Storage for input size of the list
	double  *list;  // Pointer to dynamically allocated array.
	ofstream outputFile; // to send output to .txt file to print

	//open outputFile
	outputFile.open("lab3task1.txt");

	// Get the size of the array.
	cout << "Enter the array size: \n";
	outputFile << "Enter the array size: \n";
	cin >> listsize;

	//  Allocate an array of the specified size.

	list = new double[listsize];

	//  Read in the array elements.
	cout << "Enter the array elements: \n";
	outputFile << "Enter the array elements: \n";
	for (int j = 0; j < listsize; j++)
		cin >> *(list + j);

	//  Output the array elements.
	cout << "The array contains: \n";
	outputFile << "The array contains: \n";
	for (int j = 0; j < listsize; j++)
	{
		cout << *(list + j) << " ";
		outputFile << *(list + j) << " ";
	}

	//  Deallocate the memory used to store the string.
	delete[] list;
	list = nullptr;

	// close outputFile
	outputFile.close();
}
