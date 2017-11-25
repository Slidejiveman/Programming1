#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Abstract Data Types
struct TransactionType
{
	char itemID[7];
	int buyerNum;
	float amount;
};

struct ItemType
{
	char itemID[7];
	char description[31];
	float minimumBid;
};

struct BuyerType
{
	char buyerName[12];
	int buyerNum;
};

struct SellerType
{
	char sellerName[12];
	char sellerID[3];
};

ifstream buyerList;

// Function Definitions
int showMenu();

// Main
void main()
{
	buyerList.open("buyerlist.dat", ios::binary);

	if (!buyerList)
	{
		cout << "The binary file did not open.\n";
		exit(0);
	}

	// Local Variables
	BuyerType buyer;

	// Collect Buyer Number. If returns -1, program quits
	buyer.buyerNum = showMenu();

	//read in from binary file to test it
	for (int i = 1; i <= 17; i++)
	{
		// read next entry
		buyerList.read(reinterpret_cast<char *>(&buyer), sizeof(buyer));
		cout << left << setw(12)
			<< buyer.buyerName << right << setw(4) << buyer.buyerNum << endl;
	}

	//close files
	buyerList.close();
}

//Function Definitions
int showMenu()
{
	// Local variable used in determining the course of action
	int selection;

	do
	{
		// Display the Menu options
		cout << "Please enter the buyer number you want to search for. "
			<< " Enter -1 when you are finished. \n";
		cin >> selection;

		// Bounds checking
		if (selection < 1 || selection > 17)
		{
			cout << selection << " is not a valid buyer number.\n\n\n";
		}
	} while (selection != -1);

	return selection;
}