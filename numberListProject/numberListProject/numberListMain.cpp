// This program demonstrates a simple append
// operation on a linked list.
#include <iostream>
#include <fstream>
#include "NumberList.h"
using namespace std;

int displayMenu();
void collectData();

int main()
{
	// open files for the program
	ofstream sampleOutput("programmingAssn4.txt");

	// Variable declarations.
	NumberList list;					// Nodes of the list
	int selection;						// Sentinel for loop

	// menu allowing the user to select an action
	do
	{
		//collect user's choice of action
		selection = displayMenu();

		//***************************************************
		//Each selection option must be handled in turn. The 
		//first condition performs bounds checking. The second
		//inserts a node; the third removes a node; the fourth
		// prints a node; the fifth searches for a node; finally
		// the sixth ends the program
		//***************************************************
		if (selection == 1)
		{
			collectData();
		}
		else if (selection == 2)
		{
			collectData();
		}
		else if (selection == 3)
		{
			list.displayList();
		}
		else
		{
			collectData();
		}
	
	} while (selection != 0);

	return 0;
}

//***************************************************
//collectData()
//***************************************************
int displayMenu()
{
	// Local variable used in determining the course of action
	int selection;

	// Display the Menu options
		cout << "Please select what you would like to do. \n"
			<< "1. Insert \n"
			<< "2. Remove \n"
			<< "3. Print \n"
			<< "4. Find \n"
			<< "0. Exit the program \n";
		cin >> selection;
		
		// Handle bounds checking on selection
		while (selection < 0 || selection > 4)
		{
			cout << "That was not a valid menu selection."
				<< "Please try again";
			cin >> selection;
		}

	// Return valid entry
	return selection;
}
//***************************************************
//collectData()
//***************************************************
void collectData()
{
	cout << "Please enter the item number\n";
	cin.getline(variable, size);
}