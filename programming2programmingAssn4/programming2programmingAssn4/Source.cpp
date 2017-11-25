//====================================================================
// Ryder Dale Walton
//4-6-15
//Programming Assignment #4
//Description: Auction Record Linked List
//====================================================================

/*This program allows the user several different options, each corresponding
to a linked list operation. First, the user may insert a new node--representing a
singular transaction at an auction. Second, the user may delete a node that is 
already present on the list. If the node in question does not exist in the list,
the function alerts the user to this. Third, the user may print the contents of
the list. Fourth, the user can search the list to see if a particular node exists
within the list--returning true or false. The final option the user has is to
terminate the program. This is an Object Oriented Program that also makes use
of a few procedural programming techniques. It produces output to a .txt file,
refered to by the file stream object sampleOutput.*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "AuctionRecord.h"

using namespace std;

//Data Structure
struct AuctionDataType
{
	char itemNumber[6];				// Holds two chars and three nums
	char buyerName[12];				// Holds name of the buyer
	char sellerName[12];			// Holds name of the seller
	double finalBid;				 // Money value of transaction
};

// Function Prototypes
int displayMenu();
AuctionDataType collectData();
void displayHeader();

//Global File Stream Object for text file output
ofstream sampleOutput;

//***************************************************
//The main function handles the logic trees that the
//menu function provides. It also closes the file and
//contains all of the high level function calls.
//Variables: auctionTransaction = instance of 
//					AuctionRecord class
//			 auctionData = holds entered data sent to
//					the class member functions
//			 selection = integer controlling the menu
//			 isFound = bool controlling find print
//					statements
//Arguments: None
//Return: 0 = an integer that signals the end of program
//***************************************************
int main()
{
	// open file for the program
	sampleOutput.open("programmingAssn4.txt");

	// Variable declarations.
	AuctionRecord auctionTransaction;					// Nodes of the list
	AuctionDataType auctionData;						// Used to send data to class
	int selection;										// Sentinel for main loop
	bool isFound;										// Bool for find function

	//set output format
	cout << fixed << showpoint << setprecision(2);
	sampleOutput << fixed << showpoint << setprecision(2);

	// menu allowing the user to select an action
	do
	{
		//collect user's choice of action
		selection = displayMenu();

		//***************************************************
		//Each selection option must be handled in turn. 
		//***************************************************
		
		// The insert a node routine 
		if (selection == 1)
		{
			// collect the data from the user
			auctionData = collectData();

			// insert the node into the list in the appropriate location
			auctionTransaction.insertNode(auctionData.itemNumber, auctionData.buyerName,
				auctionData.sellerName, auctionData.finalBid);
		}
		// The delete a node routine
		else if (selection == 2)
		{
			// collect the data from the user
			cout << "Please enter the five character item number\n";
			cin.getline(auctionData.itemNumber, 6);

			// delete the desired node
			auctionTransaction.deleteNode(auctionData.itemNumber);
		}
		// The display list routine
		else if (selection == 3)
		{
			auctionTransaction.displayList();
		}
		// The find a node routine
		else if (selection == 4)
		{
			// collect data from the keyboard
			cout << "Please enter the five character item number\n";
			cin.getline(auctionData.itemNumber, 6);

			// search for the desired node
			isFound = auctionTransaction.findNode(auctionData.itemNumber);

			// return whether or not the node exists in the list
			if (isFound)
			{
				cout << "That item is in the list. \n";
				sampleOutput << "That item is in the list. \n";
			}
			else
			{
				cout << "That item is NOT in the list. \n";
				sampleOutput << "That item is NOT in the list. \n";
			}

		}
		// The exit message, shown if user selects 0
		else
		{
			cout << "Thank you for using this program. Goodbye.\n";
			sampleOutput << "Thank you for using this program. Goodbye.\n";
		}
	} while (selection != 0); // if the user selects 0, the program terminates

	//close outputFile
	sampleOutput.close();

	//exit program
	return 0;
}

//***************************************************
//displayMenu() accepts no arguments, but returns an
//int to main, which is used to determine which of the
//branching paths the program should take. It's main
//job, then, is to be the decision center of the 
//program itself. It also handles the bounds checking
//for the menu.
//Variables: selection = integer controlling the menu
//Arguments: None
//Return: selection = also controls the if statements
//						back in main
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

	//skip the newline escape sequence in the buffer
	cin.ignore();

	// Handle bounds checking on selection
	while (selection < 0 || selection > 4)
	{
		cout << "That was not a valid menu selection."
			<< "Please try again";
		cin >> selection;
		cin.ignore();
	}

	// Return valid entry
	return selection;
}
//***************************************************
//collectData() accepts no argument and returns a fully
//loaded function to main. This function gathers all
//of the data needed to insert a node into the list
//Variables: userEntry = dummy struct to return fields
//						to main.
//Arguments: None
//Return: userEntry = AuctionDataType struct used to pass
//				the entered data to the class member
//				functions
//***************************************************
AuctionDataType collectData()
{
	// Local variable is a dummy struct, returned with user data
	AuctionDataType userEntry;

	// Accept user input from the keyboard
	cout << "Please enter the five character item number\n";
	cin.getline(userEntry.itemNumber, 6);

	cout << "Please enter the seller name in 11 characters or less. \n";
	cin.getline(userEntry.sellerName, 12);

	cout << "Please enter the buyer name in 11 characters or less. \n";
	cin.getline(userEntry.buyerName, 12);

	cout << "Please enter the final bid amount. \n";
	cin >> userEntry.finalBid;

	//skip the newline sequence as a precaution
	cin.ignore();

	//return dummy struct
	return userEntry;
}

