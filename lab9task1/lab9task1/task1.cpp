#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

struct SellerType
{
	char sellerName[12];
	char sellerID[3];
};

int main()
{
	SellerType seller; //instance of struct

	//open file streams
	ofstream sellerListTXT("seller_list.txt");
	fstream sellerListBin("sellerlist.dat", ios::out | ios::binary);

	//check for successful open
	if (sellerListTXT.fail())
	{
		cout << "The TEXT file did not open properly.\n";
		exit(0);
	}
	if (sellerListBin.fail())
	{
		cout << "The BINARY file did not open properly.\n";
		exit(0);
	}

	//collect data from the keyboard
	for (int i = 1; i <= 17; i++)
	{
		cout << "Enter the seller's name followed by their ID\n";
		cin >> seller.sellerName;
		cout << "Enter the Seller ID\n";
		cin >> seller.sellerID;
		sellerListBin.write(reinterpret_cast<char *>(&seller), sizeof(seller));
		// test cout
		cout << seller.sellerName << " " << seller.sellerID << endl;
	} 
	//read in contents of binary file and write them to txt file 
	cout << "Seller Name" << " Seller ID\n\n";
	sellerListTXT << "Seller Name" << " Seller ID\n\n";
	
	//close and reopen file for input
	sellerListBin.close();
	sellerListBin.open("sellerlist.dat", ios::in | ios::binary);

	//prime the while loop
	//sellerListBin.read(reinterpret_cast<char *>(&seller), sizeof(seller));
	for (int i = 1; i <= 17; i++)
	{
		// read next entry
		sellerListBin.read(reinterpret_cast<char *>(&seller), sizeof(seller));
		cout << left << setw(12) 
			<< seller.sellerName << right << setw(4) << seller.sellerID << endl;
		sellerListTXT << left << setw(12) << seller.sellerName << left << setw(4)
			<< seller.sellerID << endl;
	}

	//close files
	sellerListBin.close();
	sellerListTXT.close();

	return 0;
}