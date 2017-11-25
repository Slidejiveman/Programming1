// Implementation file for the AuctionRecord class
#include <iostream>				 // For cout
#include <iomanip>				// For formatting
#include <fstream>				// For file operations
#include "AuctionRecord.h"		// For object class

using namespace std;

// Connects the externally declared file stream object
extern ofstream sampleOutput;

//***************************************************
//displayHeader() is a helper function that works with
//the displayList() function. It is called to throw up
//the header before displaying the nodes in the list.
//Variables: None
//Arguments: None
//Returns: None
//***************************************************
void displayHeader()
{
	// display the header
	cout << "List Contents: \n\n";
	cout << left << setw(7) << "Item ID" << right << setw(12)
		<< "Seller" << right << setw(12) << "Buyer" << right
		<< setw(15) << right << "Sales Price\n"
		<< "----------------------------------------------\n";

	 sampleOutput << left << setw(7) << "Item ID" << right << setw(12)
		<< "Seller" << right << setw(12) << "Buyer" << right
		<< setw(15) << right << "Sales Price\n"
		<< "----------------------------------------------\n";
}

//**************************************************
// findNode scours the list, returning a bool, which
// indicates whether or not the item was found in the
// list.
// Variables: *nodePtr = traverses the list
// Arguments: itemNum[6] = item number passed from main
//							used for searching
// Returns: found = determines whether search value
//					was found in the list
//**************************************************
bool AuctionRecord::findNode(char itemNum[6])
{
	AuctionNodeType *nodePtr;  // To move through the list
	bool found = false;		// Returned to main, controls a cout

	// If the list is empty, display as such
	if (!head)
	{
		// Since the list is empty, notify the user
		cout << "\nThe list is empty.\n\n";
		
		//return value, the search doesn't need to happen
		return found;
	}

	// Determine if the first node is the one.
	if (strcmp(head->itemNumber, itemNum) == 0)
	{
		found = true;
	}
	// If it is not the head, then it might follow
	else
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// search through the list while you have somewhere to look and you
		// haven't found what you are looking for
		while (nodePtr != nullptr && !found)
		{
						// Set the bool based on whether or not the goal is found
			if (strcmp(nodePtr->itemNumber, itemNum) == 0)
			{
				found = true;
			}
			 
			//advance pointer
			nodePtr = nodePtr->next;
		}
	}

	//return found value after the search
	return found;
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
// Variables: *nodePtr = traverses the list
// Arguments: None
// Return: None
//**************************************************

void AuctionRecord::displayList() const
{
	AuctionNodeType *nodePtr;  // To move through the list

	// If the list is empty, display as such
	if (!head)
	{
		cout << "\nThe list is empty.\n\n";
		sampleOutput << "\nThe list is empty.\n\n";
		return;
	}
	// Position nodePtr at the head of the list.
	nodePtr = head;

	// Display the list header
	displayHeader();

	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr)
	{
		// Display the value in this node.
		cout << left << setw(7) << nodePtr->itemNumber 
			<< right << setw(12) << nodePtr->sellerName 
			<< right << setw (12) << nodePtr->buyerName
			<< right << setw(10) << "$" << nodePtr->finalBid 
			<< endl << endl;

		sampleOutput << left << setw(7) << nodePtr->itemNumber
			<< right << setw(12) << nodePtr->sellerName
			<< right << setw(12) << nodePtr->buyerName
			<< right << setw(10) << "$" << nodePtr->finalBid
			<< endl << endl;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

//**************************************************
// The insertNode function inserts a node with     *
// num copied to its value member.                 *
// Variables: *newNode = the newly created node
//			  *nodePtr = traverses the list
//			  *previousNode = holds address of last
//								node before current
// Arguments: itemNum[6] = item number from main
//			  buyName[12] = buyer's name from main
//			  sellName[12] = seller's name from main
//			  highBid = winning bid amount from main
// Return: NONE
//**************************************************

void AuctionRecord::insertNode(char itemNum[6], char buyName[12], char sellName[12], double highBid)
{
	AuctionNodeType *newNode;					// A new node
	AuctionNodeType *nodePtr;					// To traverse the list
	AuctionNodeType *previousNode = nullptr;	// The previous node

	// Allocate a new node and store num there.
	newNode = new AuctionNodeType;
	strcpy_s(newNode->itemNumber, itemNum);
	strcpy_s(newNode->buyerName, buyName);
	strcpy_s(newNode->sellerName, sellName);
	newNode->finalBid = highBid;
	
	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else  // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = nullptr;

		// Skip all nodes whose value is less than num.
		while (nodePtr != nullptr && strcmp(nodePtr->itemNumber, itemNum) < 0)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else  // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
	// generate feedback to track the computer's actions
	cout << newNode->itemNumber << " was added to the list. \n";
	sampleOutput << newNode->itemNumber << " was added to the list. \n";
}

//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.		   *
// Variables: *nodePtr = walks through the list
//			  *previousNode = holds previous node
//								address
// Arguments: itemNum[6] = item number from main
// Return: None
//**************************************************

void AuctionRecord::deleteNode(char itemNum[6])
{
	AuctionNodeType *nodePtr;				  // To traverse the list
	AuctionNodeType *previousNode = nullptr;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (strcmp(head->itemNumber, itemNum) == 0)
	{
		// Delete the node at the head
		nodePtr = head->next;
		delete head;
		head = nodePtr;

		// generate feedback to track the computer's actions
		cout << itemNum << " was removed from the list. \n";
		sampleOutput << itemNum << " was removed from the list. \n";
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to the itemNumber code.
		while (nodePtr != nullptr && strcmp(nodePtr->itemNumber, itemNum) != 0)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the desired item is not in the list, print that it is so
		if (nodePtr == nullptr)
		{
			cout << "That item was not in the list, so it was not deleted.\n\n";
			sampleOutput << "That item was not in the list, so it was not deleted.\n\n";
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;

			// generate feedback to track the computer's actions
			cout << itemNum << " was removed from the list. \n";
			sampleOutput << itemNum << " was removed from the list. \n";
		}

	}
}
	

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// Variables: *nodePtr: steps through the list
//			  *nextNode: holds address of next node
//							to be deleted
//**************************************************

AuctionRecord::~AuctionRecord()
{
	AuctionNodeType *nodePtr;   // To traverse the list
	AuctionNodeType *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}