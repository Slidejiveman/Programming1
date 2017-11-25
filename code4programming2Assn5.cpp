//====================================================================
// Joshua Davidson, Colten Humphrey, and Ryder Dale Walton           =
// 4-17-15															 =
// Programming Assignment #5										 =
// Description: Fish Auction Reports								 =
//====================================================================

/*This program allows the user to enter a buyer number associated with
17 individuals who participated in a fish auction. As long as the user
does not enter a 0 from the keyboard, the program will continue to loop
and produce as many as reports as desired. If the particular buyer 
number does not exist, then the program alerts the user to this fact.
This is a Procedural Program as it does not rely on any objects or 
programmer defined header files. It produces output to a .txt file, refered 
to by the file stream object named outputFile.*/

#include <iostream>								
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

//====================================================================
// These are the abstract data types used for the program. The first =
// four are used to hold the data read in from the four binary files.=
// The last one defines the global structure used to create reports. =
// Together, these allow for simple comparisons to be made with the  =
// the user's entered number.										 =
//====================================================================

// SoldType holds the information from the transaction record
struct SoldType
{
	char soldName[12];						// Item ID from ItemType is the same
	int buyerNum;							// Same number from BuyerType
	float soldFor;							// Final sale amount
};
// ItemType holds the specific information about the individual items 
struct ItemType
{
	char itemID[7];							// 2 Letters, 3 Numbers
	char itemDescription[31];				// Name of the fish
	float minBid;							// Not necessary for program
};
// BuyerType holds the name and number of the buyer 
struct BuyerType
{
	char buyerName[12];						// Buyer's first name only
	int buyerNum;							// Used to search for buyer name
};
// SellerType holds the name and ID letters of the seller
struct SellerType
{
	char sellerName[12];					// Seller's first name only
	char sellerID[3];						// First two letters of name
};
// ReportType holds all of the necessary pieces for reports 
struct ReportType
{
	char buyerName[12];						// Store's buyerName from BuyerType
	char itemID[5][7];						// Holds item ID from ItemType
	float salePrice[5];						// Holds final price from SoldType
	char itemDescription[5][31];			// Holds fish name from ItemType
	char sellerName[5][12];					// Holds seller name from SellerType
	char sellerID[5][3];					// Holds seller ID from SellerType
};

// Function Prototypes: More Detail Follows
void readBuyerBin(BuyerType buyers[]);
void readSellerBin(SellerType sellers[]);
void readItemsBin(ItemType items[]);
void readSoldBin(SoldType sales[]);
int getBuyerNum();
void getItemNumbers(int buyerNum, SoldType sales[]);
void getSellerName(SellerType sellers[]);
void getDescriptions(ItemType items[]);
void displayReport();

// Global File Stream Objects, prevents extra passing among functions
ofstream outputFile;						// Text file for printable output
ifstream soldList;							// Binary file with transactions
ifstream buyerList;							// Binary file with buyer info
ifstream sellerList;						// Binary file with seller info
ifstream itemList;							// Binary file with item info

// Global Report Data Structure Object, prevents excessive function parameters
ReportType report;							// Object associated with report info

//********************************************************************************
// The main function is the top level of the program. It contains the main loop  *
// that runs until the user enters a 0 from the keyboard. It calls all of the    *
// functions that collect the information needed to display the reports before   * 
// calling the function that displays the report information. It also controls   *
// The file operations and error checking.										 * 
// Variables: sellers = an array of seller names and IDs						 *
//			 buyers = an array of buyer names and IDs							 *
//			 items = an array of item numbers, descriptions, and minimum bids    *
//			 sales = an array holding item numbers, buyer IDs, and amount due    *
//			 buyerNum = search parameter entered from keyboard, startrs searches *
// Arguments: None																 *
// Return: 0 = an integer that signals the end of program						 *
//********************************************************************************
int main()
{
	// Local Variables
	SellerType sellers[17];					// Structs containing all seller info
	BuyerType buyers[17];					// Structs containing all buyer info
	ItemType items[28];						// Structs containing all item info
	SoldType sales[28];						// Structs contianing transaction info
	int buyerNum;							// Number entered from keyboard

	// Check for successful file opens, exit if one fails
	outputFile.open("buyer_statement.txt");
	if (outputFile.fail())
	{
		cout << "buyer_statement.txt failed to open\n";
		exit(0);
	}
	soldList.open("soldlist.bin", ios::binary);
	if (soldList.fail())
	{
		cout << "soldlist.bin failed to open\n";
		exit(0);
	}
	buyerList.open("buyerlist.bin", ios::binary);
	if (buyerList.fail())
	{
		cout << "buyerlist.bin failed to open\n";
		exit(0);
	}
	itemList.open("itemlist.bin", ios::binary);
	if (itemList.fail())
	{
		cout << "itemlist.bin failed to open\n";
		exit(0);
	}
	sellerList.open("sellername.bin", ios::binary);
	if (sellerList.fail())
	{
		cout << "sellerlist.bin failed to open\n";
		exit(0);
	}
	
	// Read in the data from the binary files, see functions
	readBuyerBin(buyers);
	readSellerBin(sellers);
	readItemsBin(items);
	readSoldBin(sales);

	// Collect search number from user, controls main loop
	buyerNum = getBuyerNum();

	// MAIN LOOP
	while (buyerNum != 0)							// Exits program when 0 entered
	{
		// Collect data from the arrays to populate report object
		strcpy_s(report.buyerName, buyers[buyerNum - 1].buyerName);
		getItemNumbers(buyerNum, sales);
		getSellerName(sellers);
		getDescriptions(items);
		
		// Dislplay all of the collected report information
		displayReport();

		// Collect next buyer number
		buyerNum = getBuyerNum();
	}
	// Signal Program End
	return 0;
}

//********************************************************************************
// getBuyerNum collects the initial search parameter from the user. Also, it     *
// Outputs when there is no matching buyer number in the arrays.				 * 
// Variables: buyerNum = entered from the computer, controls the main loop and   * 
// the if condition and while loop found in the function itself. 				 *
// Arguments: None																 *
// Return: buyerNum = an integer used to control the main loop in main			 *
//********************************************************************************
int getBuyerNum()
{
	// Local Variable
	int buyerNum;								// User entered sentinel control

	// Prompt to the user
	cout << "What is the buyer number? 0 to exit" << endl;
	cin >> buyerNum;

	// Bounds checking for data entry
	if (buyerNum > 17 || buyerNum < 0)
	{
		while (buyerNum > 17 || buyerNum < 0)
		{
			// Display if the number doesn't match a buyer number
			cout << buyerNum << " doesn't exist" << endl;
			outputFile << buyerNum << " doesn't exist" << endl;

			// Prompt again if there is an error
			cout << "What is the buyer number? 0 to exit" << endl;
			cin >> buyerNum;
		}
	}
	return buyerNum;
}

//********************************************************************************
// The readBuyerBin function reads the buyer information from the binary file and*
// stores it in the arrays used in this program.								 * 
// Variables: None															     *
// Arguments: buyers = array to hold read in data								 *
// Return: None																	 *
//********************************************************************************
void readBuyerBin(BuyerType buyers[])
{
	// For loop since it is designed to work with our previous program
	for (int i=0; i < 17; i++)
	{
		buyerList.read(reinterpret_cast<char *> (&buyers[i]), sizeof(buyers[i]));
	}
}

//********************************************************************************
// The readSellerBin function reads the buyer information from the binary file   *
// and stores it in the arrays used in this program.							 * 
// Variables: None															     *
// Arguments: sellers = array to hold read in data								 *
// Return: None																	 *
//********************************************************************************
void readSellerBin(SellerType sellers[])
{
	for (int i = 0; i < 17; i++)
	{
		sellerList.read(reinterpret_cast<char *> (&sellers[i]), sizeof(sellers[i]));
	}
}

//********************************************************************************
// The readItemsBin function reads the buyer information from the binary file    *
// and stores it in the arrays used in this program.							 * 
// Variables: None															     *
// Arguments: items = array to hold read in data								 *
// Return: None																	 *
//********************************************************************************
void readItemsBin(ItemType items[])
{
	for (int i = 0; i < 28; i++)
	{
		itemList.read(reinterpret_cast<char *> (&items[i]), sizeof(items[i]));
	}
}

//********************************************************************************
// The readSoldBin function reads the buyer information from the binary file     *
// and stores it in the arrays used in this program.							 * 
// Variables: None															     *
// Arguments: sales = array to hold read in data								 *
// Return: None																	 *
//********************************************************************************
void readSoldBin(SoldType sales[])
{
	for (int i = 0; i < 28; i++)
	{
		soldList.read(reinterpret_cast<char *> (&sales[i]), sizeof(sales[i]));
	}
}

//********************************************************************************
// The getItemNumbers function uses the entered buyerNum to find the associated  *
// items numbers in the array. It them truncates the numbers off of the item     *
// numbers, which creates the seller IDs that are also needed for the reports.   * 
// Variables: j = an integer used as a 2D array counter						     *
// Arguments: buyerNum = an integer used to find the itemIDs of the sellers      *
//			  sales = array containing all of the transaction information		 *
// Return: None																	 *
//********************************************************************************
void getItemNumbers(int buyerNum, SoldType sales[])
{
	// Local Variable
	int j = 0;									// Row counter controller

	// Maximum number of column counts is total number of items
	for (int i = 0; i < 28; i++)
	{
		// Loop is checking to see if user entered number matches buyerNum in array
		if (buyerNum == sales[i].buyerNum)
		{
			// If the numbers match, copy it to the report file
			strcpy_s(report.itemID[j], sales[i].soldName);
			report.salePrice[j] = sales[i].soldFor;

			// Grab the two letters off of the item numbers to make the seller ID
			strncpy_s(report.sellerID[j], report.itemID[j], 2);

			j++;								// Increment the j counter
		}
	}
}

//********************************************************************************
// getSellerName checks each index in the seller array against all of the		 *
// rows in the global 2D report.sellerID array. This allows us to be certain that*
// we will not skip over one of the needed array elements in our search.		 *
// Variables: None															     *
// Arguments: sellers = contains seller information to search for        		 *
// Return: None																	 *
//********************************************************************************
void getSellerName(SellerType sellers[])
{
	// The loop controls each of the rows in the 2D array with the current index
	for (int i = 0; i < 17; i++)
	{
		// We have allowed for only 5 rows in this search due to sample size
		if (strcmp(report.sellerID[0], sellers[i].sellerID) == 0)
		{
			strcpy_s(report.sellerName[0], sellers[i].sellerName);
			cout << report.sellerName[0]<<endl;
		}
		else if (strcmp(report.sellerID[1], sellers[i].sellerID) == 0)
		{
			strcpy_s(report.sellerName[1], sellers[i].sellerName);
			cout << report.sellerName[1]<<endl;
		}
		else if (strcmp(report.sellerID[2], sellers[i].sellerID) == 0)
		{
			strcpy_s(report.sellerName[2], sellers[i].sellerName);
			cout << report.sellerName[2]<< endl;
		}
		else if (strcmp(report.sellerID[3], sellers[i].sellerID) == 0)
		{
			strcpy_s(report.sellerName[3], sellers[i].sellerName);
			cout << report.sellerName[3] << endl;
		}
		else if (strcmp(report.sellerID[4], sellers[i].sellerID) == 0)
		{
			strcpy_s(report.sellerName[4], sellers[i].sellerName);
			cout << report.sellerName[4] << endl;
		}
	}
}

//********************************************************************************
// getDescriptions checks each index in the items array against all of the       *
// rows in the global 2D report.itemID array. This allows us to be certain that  *
// we will not skip over one of the needed array elements in our search.		 *
// Variables: None															     *
// Arguments: items = contains item description        		 *
// Return: None																	 *
//********************************************************************************
void getDescriptions(ItemType items[])
{
	// The logic here is the same as the getSellerName function, but with more elements
	for (int i = 0; i < 28; i++)
	{
		if (strcmp(report.itemID[0], items[i].itemID) == 0)
		{
			strcpy_s(report.itemDescription[0], items[i].itemDescription);
			cout << report.itemDescription[0] << endl;
		}
		else if (strcmp(report.itemID[1], items[i].itemID) == 0)
		{
			strcpy_s(report.itemDescription[1], items[i].itemDescription);
			cout << report.itemDescription[1] << endl;
		}
		else if (strcmp(report.itemID[2], items[i].itemID) == 0)
		{
			strcpy_s(report.itemDescription[2], items[i].itemDescription);
			cout << report.itemDescription[2] << endl;
		}
		else if(strcmp(report.itemID[3], items[i].itemID) == 0)
		{
			strcpy_s(report.itemDescription[3], items[i].itemDescription);
			cout << report.itemDescription[3] << endl;
		}
		else if (strcmp(report.itemID[4], items[i].itemID) == 0)
		{
			strcpy_s(report.itemDescription[4], items[i].itemDescription);
			cout << report.itemDescription[4] << endl;
		}
	}
}

//********************************************************************************
// The displayReport function sends all of the collected data to an output file  *
// and also shows it to the screen. It starts by formatting the displays and     *
// showing the headers. It then runs through the rows of the ReportType objects  *
// collected data and displays all of the necessary information appropriately    *
// formatted. The test for this loop is whether or not the report.salePrice has  *
// a zero in it. The loop also calculates the amount due for each buyer. Next,   *
// the function prints the header of the report. Finally, it resets all of the   *
// held prices to 0 so that uneeded rows are not displayed and sent to the output*
// file.																		 * 
// Variables: j = an integer used to control row counting						 *
//			 totalDue = a float used to hold the amount due from buyer to seller *
// Arguments: None																 *
// Return: None																	 *
//********************************************************************************
void displayReport()
{
	// Local Variables
	int j = 0;											// Controls rows of counters
	float totalDue = 0;									// Holds total amount due

	// Format display settings to outputFile and cout
	cout << showpoint << fixed << setprecision(2);
	outputFile << showpoint << fixed << setprecision(2);

	// Display the header of the report
	cout << left << setw(12) << "Buyer" << left << setw(7) << "item #" << left << setw(31) 
		<< "Description" << left << setw(7) << "Price" <<left << setw(9) << "Seller ID" 
		<< left << setw(12) << " Seller Name" << endl;
	cout << "------------------------------------------------------------------------------" 
		<< endl;
	outputFile << left << setw(12) << "Buyer" << left << setw(7) << "item #" << left 
		<< setw(31) << "Description" << left << setw(7) << "Price" << left << setw(9) 
		<< "Seller ID" << left << setw(12) << " Seller Name" << endl;
	outputFile << "------------------------------------------------------------------------------" 
		<< endl;

	// Only displays rows that do not have 0 in the report.salePrice variable. Those aren't important.
	while (report.salePrice[i]!=0)
	{
		// Display transaction information accumulated in the instance of the report struct
		cout << left << setw(12) << report.buyerName;
		cout << left << setw(7) << report.itemID[j] << left << setw(31) << report.itemDescription[j] 
			<< left << setw(7) << report.salePrice[j] << left << setw(11) << report.sellerID[j] 
			<< left << setw(12) << report.sellerName[j] << endl;
		outputFile << left << setw(12) << report.buyerName;
		outputFile << left << setw(7) << report.itemID[j] << left << setw(31) 
			<< report.itemDescription[j] << left << setw(7) << report.salePrice[j] << left 
			<< setw(11) << report.sellerID[j] << left << setw(12) << report.sellerName[j] << endl;
				
		// Calculate total amount due for each buyer
		totalDue += report.salePrice[j];
		
		// Increment counter
		j++;
	}

	// Display the footer of the report information, including calculated total due
	cout << "------------------------------------------------------------------------------" 
		<< endl;
	cout << "Total Due:" << setw(40) << right << "$" << totalDue << endl << endl << endl;
	outputFile << "------------------------------------------------------------------------------" 
		<< endl;
	outputFile << "Total Due:" << setw(40) << right << "$" << totalDue << endl << endl << endl;

	// Finally, set all sales prices back to zero before program repopulates needed fields
	// This prevents the program from displaying spurious rows of information
	for (int i = 0; i < 5; i++)
	{
		report.salePrice[i] = 0;
	}
}