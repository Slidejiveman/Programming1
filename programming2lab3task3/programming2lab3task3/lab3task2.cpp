#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

//function prototypes
char findFrequentLetter(char*, int, int&);

int main()
{
	ofstream outputFile; //to print a .txt file
	int stringLength; //holds length of dynamic array
	char *charPtr; //pointer to a C-String
	char frequentChar; //holds return value of find function
	int numberOfAppearances; //holds the number of times the above letter appeared

	//open outputFile
	outputFile.open("lab3task3.txt");

	//ask output and find frequent character
	cout << "How long is the phrase we are searching for?\n";
	cin >> stringLength;
	
	//dynamically allocate array
	charPtr = new char[stringLength];

	//input the phrase to check
	cout << "Now, please enter the string to test. \n";
	cin.get();
	cin.getline(charPtr, stringLength);//stores the line in charPtr of stringLength size

	//call find function
	frequentChar = findFrequentLetter(charPtr, stringLength, numberOfAppearances);

	//display output
	cout << frequentChar << " appears " << numberOfAppearances << " times. \n";
	outputFile << frequentChar << " appears " << numberOfAppearances << " times. \n";
	
	//delete dynamically allocated memory
	delete[] charPtr;
	charPtr = nullptr;

	//close outputFile
	outputFile.close();

	return 0;
}

char findFrequentLetter(char *charPtr, int stringLength, int &numberOfAppearances)
{
	char mostFrequent; // holds the most frequently occuring letter
	int testCounter; //checks the number of appearances of each letter

	//counters
	char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 
		'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	
	//make all letters lowercase
	for (int i = 0; i < stringLength; i++)
	{
		*(charPtr + i) = tolower(*(charPtr + i)); //convert all letters to same case
	}

	//compare characters with the letters in the alphabet
	numberOfAppearances = 0;//accumulator for appearances
	for (int j = 0; j < 26; j++)
	{
		testCounter = 0;
		for (int i = 0; i < stringLength; i++)
		{
			if (*(charPtr + i) == alphabet[j])
				testCounter++;

			//test to see maximum number of appearances
			if (testCounter > numberOfAppearances)
			{
				numberOfAppearances = testCounter;
				mostFrequent = *(charPtr + i);
			}
		}
	}
	return mostFrequent;
}