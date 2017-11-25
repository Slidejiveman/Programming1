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
programmer defined header files. It produces output to a .txt file, referred
to by the file stream object named outputFile. The production of this output
relies on an array; however, no other process in the program uses arrays.
Information is read directly from the binary files using the read() function*/

#include <iostream>								
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

//====================================================================
// These are the abstract data types used for the program. The first =
// four are used to hold single records read in from binary files.   =
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
int getBuyerNum();
void getBuyerName(int buyerNum, BuyerType &buyers);
void getItemNumbers(int buyerNum, SoldType &sales);
void getSellerName(SellerType &sellers);
void getDescriptions(ItemType &items);					
void displayReport();

// Global File Stream Object, prevents extra passing among functions
ofstream outputFile;						// Text file for printable output

// Global Report Data Structure Object, prevents excessive function parameters
ReportType report;							// Object associated with report info

//********************************************************************************
// The main function is the top level of the program. It contains the main loop  *
// that runs until the user enters a 0 from the keyboard. It calls all of the    *
// functions that collect the information needed to display the reports before   * 
// calling the function that displays the report information. It also controls   *
// the outputFile stream object.												 * 
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
	SellerType sellers;					// Structs containing all seller info
	BuyerType buyers;					// Structs containing all buyer info
	ItemType items;						// Structs containing all item info
	SoldType sales;						// Structs contianing transaction info		
	int buyerNum;						// Number entered from keyboard

	// Check for successful file opens, exit if one fails
	outputFile.open("buyer_statement.txt");
	if (outputFile.fail())
	{
		cout << "buyer_statement.txt failed to open\n";
		exit(0);
	}
	
	// Collect search number from user, controls main loop
	buyerNum = getBuyerNum();

	// MAIN LOOP
	while (buyerNum != 0)							// Exits program when 0 entered
	{
		// Collect data from the arrays to populate report object
		getBuyerName(buyerNum, buyers);
		getItemNumbers(buyerNum, sales);
		getSellerName(sellers);
		getDescriptions(items);

		// Dislplay all of the collected report information
		displayReport();

		// Collect next buyer number
		buyerNum = getBuyerNum();
	}

	// Close outputFile
	outputFile.close();

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

	// Return integer back to main
	return buyerNum;
}

//********************************************************************************
// The getBuyerName function uses the entered buyerNum to find the associated    *
// buyer name from the buyerList binary file. It reads the information straight  *
// from the file without using unnecessary arrays. The main processing of this   *
// function is a while loop that searches until it finds the buyer name it wants.* 
// Variables: None															     *
// Arguments: buyerNum = an integer used to find the itemIDs of the sellers      *
//			  buyers = struct with necessary fields to find wanted information.	 *
// Return: None																	 *
//********************************************************************************
void getBuyerName(int buyerNum, BuyerType &buyers)
{
	// Local File Stream Object
	ifstream buyerList;								// Binary file with buyer info

	// Open and test file
	buyerList.open("buyerlist.bin", ios::binary);
	if (buyerList.fail())
	{
		cout << "buyerlist.bin failed to open\n";
		exit(0);								   // Exits if file input fails
	}

	// Read in the first record from the struct, primes loop.
	buyerList.read(reinterpret_cast<char *> (&buyers), sizeof(buyers));
	if (buyerNum == buyers.buyerNum)
		strcpy_s(report.buyerName, buyers.buyerName);

	// If the associated buyerNum is the one currently held by the struct,
	// the loop quits as it has found the record with the correct name
	while (buyerNum != buyers.buyerNum)
	{
		buyerList.read(reinterpret_cast<char *> (&buyers), sizeof(buyers));			
		if (buyerNum == buyers.buyerNum)
			strcpy_s(report.buyerName, buyers.buyerName);
	}

	// Close the buyerList file to reset file pointers after each run
	buyerList.close();																
}

//********************************************************************************
// The getItemNumbers function uses the entered buyerNum to find the associated  *
// items numbers in the soldList binary file. It then truncates the numbers off  * 
// of the first two letters off of the item numbers, which creates the seller    *
// IDs that are also needed for the reports.									 * 
// Variables: j = an integer used as the report object's 2D array counter	     *
// Arguments: buyerNum = an integer used to find the itemIDs of the sellers      *
//			  sales = holds individual instances of the transaction information	 *
// Return: None																	 *
//********************************************************************************
void getItemNumbers(int buyerNum, SoldType &sales)
{
	// Local Filestream Object
	ifstream soldList;							// Binary file with transactions

	// Test file for successful open
	soldList.open("soldlist.bin", ios::binary);
	if (soldList.fail())
	{
		cout << "soldlist.bin failed to open\n";
		exit(0);
	}

	// Local Variable
	int j = 0;									// Row counter controller

	// Prime the EOF while loop for its search
	soldList.read(reinterpret_cast<char *> (&sales), sizeof(sales));			
	while (!(soldList.eof()))															
	{
		// Condition is checking to see if user entered number matches buyerNum in array
		if (buyerNum == sales.buyerNum)
		{
			// If the numbers match, copy it to the report file
			strcpy_s(report.itemID[j], sales.soldName);
			report.salePrice[j] = sales.soldFor;									

			// Grab the two letters off of the item numbers to make the seller ID
			strncpy_s(report.sellerID[j], report.itemID[j], 2);

			// Increment the j counter
			j++;											
		}

		// Read next set of data
		soldList.read(reinterpret_cast<char *> (&sales), sizeof(sales));			
	}

	// Reset the file
	soldList.close();																
}

//********************************************************************************
// getSellerName checks each index in the seller binary file against all of the	 *
// rows in the global 2D report.sellerID array. This allows us to be certain that*
// we will not skip over one of the needed seller names in our search.			 *
// Variables: None															     *
// Arguments: sellers = holds instances of seller info from binary file			 *
// Return: None																	 *
//********************************************************************************
void getSellerName(SellerType &sellers)
{
	// Local Filestream Object
	ifstream sellerList;						// Binary file with seller info

	// Check for successful file open
	sellerList.open("sellername.bin", ios::binary);
	if (sellerList.fail())
	{
		cout << "sellerlist.bin failed to open\n";
		exit(0);
	}

	// Prime while EOF loop
	sellerList.read(reinterpret_cast<char *> (&sellers), sizeof(sellers));			

	// The loop controls each of the rows in the 2D array with the current index
	while (!(sellerList.eof()))
	{
		// We have allowed for only 5 rows in this search due to sample data size.
		// The greatest amount of data ever needed for this particular auction 
		// would be 28, but since the program is written after the events of the
		// auction, no more than 5 items where purchased by any one individual.
		if (strcmp(report.sellerID[0], sellers.sellerID) == 0)
		{
			strcpy_s(report.sellerName[0], sellers.sellerName);
			cout << report.sellerName[0] << endl;
		}
		else if (strcmp(report.sellerID[1], sellers.sellerID) == 0)
		{
			strcpy_s(report.sellerName[1], sellers.sellerName);
			cout << report.sellerName[1] << endl;
		}
		else if (strcmp(report.sellerID[2], sellers.sellerID) == 0)
		{
			strcpy_s(report.sellerName[2], sellers.sellerName);
			cout << report.sellerName[2] << endl;
		}																				
		else if (strcmp(report.sellerID[3], sellers.sellerID) == 0)
		{
			strcpy_s(report.sellerName[3], sellers.sellerName);
			cout << report.sellerName[3] << endl;
		}
		else if (strcmp(report.sellerID[4], sellers.sellerID) == 0)
		{
			strcpy_s(report.sellerName[4], sellers.sellerName);
			cout << report.sellerName[4] << endl;
		}

		// Read next set of data
		sellerList.read(reinterpret_cast<char *> (&sellers), sizeof(sellers));		
	
	}
	// Close to reset file pointers to the beginning
	sellerList.close();															
}

//********************************************************************************
// getDescriptions checks each index in the items binary file against all of the *
// rows in the global 2D report.itemID array. This allows us to be certain that  *
// we will not skip over one of the needed item descriptions in our search.		 *
// Variables: None															     *
// Arguments: items = contains one record of the items file at a time	  		 *
// Return: None																	 *
//********************************************************************************
void getDescriptions(ItemType &items)
{
	// Local Filestream Object
	ifstream itemList;							// Binary file with item info

	// Check for successful file open
	itemList.open("itemlist.bin", ios::binary);
	if (itemList.fail())																
	{
		cout << "itemlist.bin failed to open\n";
		exit(0);
	}			

	// Prime the while loop
	itemList.read(reinterpret_cast<char *> (&items), sizeof(items));					

	// The logic here is the same as the getSellerName function, but with more elements
	while (!(itemList.eof()))
	{
		if (strcmp(report.itemID[0], items.itemID) == 0)
		{
			strcpy_s(report.itemDescription[0], items.itemDescription);
			cout << report.itemDescription[0] << endl;
		}
		else if (strcmp(report.itemID[1], items.itemID) == 0)
		{
			strcpy_s(report.itemDescription[1], items.itemDescription);
			cout << report.itemDescription[1] << endl;
		}
		else if (strcmp(report.itemID[2], items.itemID) == 0)
		{
			strcpy_s(report.itemDescription[2], items.itemDescription);					
			cout << report.itemDescription[2] << endl;
		}
		else if (strcmp(report.itemID[3], items.itemID) == 0)
		{
			strcpy_s(report.itemDescription[3], items.itemDescription);
			cout << report.itemDescription[3] << endl;
		}
		else if (strcmp(report.itemID[4], items.itemID) == 0)
		{
			strcpy_s(report.itemDescription[4], items.itemDescription);
			cout << report.itemDescription[4] << endl;
		}

		// Get next set of data
		itemList.read(reinterpret_cast<char *> (&items), sizeof(items));			
	}

	// Close file to reset pointers to the beginning
	itemList.close();																
}

//********************************************************************************
// The displayReport function sends all of the collected data to an output file  *
// and also shows it to the screen. It starts by formatting the displays and     *
// showing the headers. It then runs through the rows of the ReportType objects  *
// collected data and displays all of the necessary information appropriately    *
// formatted. The test for this loop is whether or not the report.salePrice has  *
// a zero in it. The loop also calculates the amount due for each buyer. Next,   *
// the function prints the footers of the report. Finally, it resets all of the  *
// held prices to 0 so that uneeded rows are not displayed and sent to the output*
// file. The entire purpose for holding collected information in arrays is to    *
// have this nice display function to display all of the collected data from the *
// binary files before returning to the files to grab the next round of info for *
// the next report.																 * 
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
		<< "Description" << left << setw(7) << "Price" << left << setw(9) << "Seller ID"
		<< left << setw(12) << " Seller Name" << endl;
	cout << "------------------------------------------------------------------------------"
		<< endl;
	outputFile << left << setw(12) << "Buyer" << left << setw(7) << "item #" << left
		<< setw(31) << "Description" << left << setw(7) << "Price" << left << setw(9)
		<< "Seller ID" << left << setw(12) << " Seller Name" << endl;
	outputFile << "------------------------------------------------------------------------------"
		<< endl;

	// Only displays rows that do not have 0 in the report.salePrice variable. Those aren't important.
	while (report.salePrice[j] != 0)
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

		// Increment row counter
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