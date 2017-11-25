#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<fstream>

using namespace std;

//function prototype
string stringGame(char[], char[], char[]);

int main()
{
	ofstream outputFile; //to print output
	char string1[41], string2[10], string3[10];//hold values for function
	string finalPhrase; //holds return value of function

	//open outputFile
	outputFile.open("lab4task3.txt");
	if (outputFile)
	{
		//collect input
		cout << "What phrase or sentence would you like to be held in string1? \n"
			<< "It should be no more than 40 characters.\n";
		cin.getline(string1, 41);
		cout << "What word or phrase would you like to search for in string1? \n";
		cin.getline(string2, 10);
		cout << "What word or phrase would you like to substitute into string1? \n";
		cin.getline(string3, 10);

		//call stringGame
		finalPhrase = stringGame(string1, string2, string3);

		//display finalPhrase
		cout << finalPhrase << endl;
		outputFile << finalPhrase << endl;
	}
	else
		cout << "The outputFile did not open!\n";

	return 0;
}

//function definition
string stringGame(char string1[], char string2[], char string3[])
{
	//string returnString; //function return value
	char *string1Ptr = nullptr; //pointer to found value in string1
	char *newStringPtr = nullptr;//pointer to DMA cstring
	int spaceFromStart; //holds number of bytes from beginning to ptr
	int maxSpace; //holds calculated DMA space 

	//find the amount of space to allocate and allocate it
	string1Ptr = strstr(string1, string2);//places ptr
	spaceFromStart = string1Ptr- string1;//find space between 1Ptr and start
	maxSpace = strlen(string1) - strlen(string2) + strlen(string3) + 1;
	newStringPtr = new char[maxSpace];
	
	//read in characters up to the target
	for (int i = 0; i < spaceFromStart ; i++)
	{
		newStringPtr[i] = string1[i];
	}

	//read in the target
	for (int i = spaceFromStart; i < (spaceFromStart + strlen(string3)); i++)
	{
		newStringPtr[i] = string3[i - spaceFromStart];
	}

	//read in the remainder of the original string
	for (int i = (spaceFromStart + strlen(string3)); i < maxSpace; i++)
	{
		newStringPtr[i] = string1[i-strlen(string3) + strlen(string2)];//something needs to be done here
	}

	//set final space in string to null terminator
	newStringPtr[maxSpace-1] = '\0';
	string returnString(newStringPtr);

	//free up dynamically allocated memory and reset ptr
	delete[] newStringPtr;
	newStringPtr = nullptr;
	
	//return string object
	return returnString;
	
}