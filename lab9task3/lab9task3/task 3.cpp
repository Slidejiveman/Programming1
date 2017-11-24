#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

struct ItemType
{
	char itemID[7];
	char description[31];
	float minimumBid;
};

int main()
{
	ItemType item;		//instance of struct
	int numberOfItems = 0;	//holds number of items per seller
	int totalItems = 0;		//holds amassed number of items

	//open file streams
	ofstream itemListTXT("item_list.txt");
	fstream itemListBin("itemlist.dat", ios::out | ios::binary);

	//check for successful open
	if (itemListTXT.fail())
	{
		cout << "The TEXT file did not open properly.\n";
		exit(0);
	}
	if (itemListBin.fail())
	{
		cout << "The BINARY file did not open properly.\n";
		exit(0);
	}
	
	while (numberOfItems != -1)
	{
		cout << "How many items is this seller selling?\n";
		cin >> numberOfItems;
		cin.ignore();

		//collect data from the keyboard
		for (int i = 1; i <= numberOfItems; i++)
		{
			cout << "Enter the item ID in AANNN format\n";
			cin.getline(item.itemID, 7);
			cout << "Enter the item description\n";
			cin.getline(item.description, 31);
			cout << "Enter the minimum bid\n";
			cin >> item.minimumBid;
			cin.ignore();
			itemListBin.write(reinterpret_cast<char *>(&item), sizeof(item));
			// test cout
			cout << item.itemID << " " << item.description << " " << item.minimumBid << endl;
		}
		//add to running total
		totalItems += numberOfItems;
	}
	//read in contents of binary file and write them to txt file 
	cout << fixed << showpoint << setprecision(2);
	itemListTXT << fixed << showpoint << setprecision(2);
	cout << "Item ID" << " Description" << " Minimum Bid \n\n";
	itemListTXT << "Item ID" << " Description" << " Minimum Bid \n\n";

	//close and reopen file for input
	itemListBin.close();
	itemListBin.open("itemlist.dat", ios::in | ios::binary);

	//read in from binary file to test it
	for (int i = 1; i <= (totalItems + 1); i++)
	{
		// read next entry
		itemListBin.read(reinterpret_cast<char *>(&item), sizeof(item));
		cout << left << setw(7)
			<< item.itemID << right << setw(31) << item.description
			<< right << setw(5) << item.minimumBid << endl;
		itemListTXT << left << setw(7)
			<< item.itemID << right << setw(31) << item.description
			<< right << setw(5) << item.minimumBid << endl;
	}

	//close files
	itemListBin.close();
	itemListTXT.close();

	return 0;
}