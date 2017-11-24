#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

struct BuyerType
{
	char buyerName[12];
	int buyerNum;
};

int main()
{
	BuyerType buyer; //instance of struct

	//open file streams
	ofstream buyerListTXT("buyer_list.txt");
	fstream buyerListBin("buyerlist.dat", ios::out | ios::binary);

	//check for successful open
	if (buyerListTXT.fail())
	{
		cout << "The TEXT file did not open properly.\n";
		exit(0);
	}
	if (buyerListBin.fail())
	{
		cout << "The BINARY file did not open properly.\n";
		exit(0);
	}

	//collect data from the keyboard
	for (int i = 1; i <= 17; i++)
	{
		cout << "Enter the seller's name followed by their ID\n";
		cin >> buyer.buyerName;
		cout << "Enter the Buyer Number\n";
		cin >> buyer.buyerNum;
		buyerListBin.write(reinterpret_cast<char *>(&buyer), sizeof(buyer));
		// test cout
		cout << buyer.buyerName << " " << buyer.buyerNum << endl;
	}
	//read in contents of binary file and write them to txt file 
	cout << "Buyer" << " Buyer Number \n\n";
	buyerListTXT << "Buyer" << " Buyer Number \n\n";

	//close and reopen file for input
	buyerListBin.close();
	buyerListBin.open("buyerlist.dat", ios::in | ios::binary);

    //read in from binary file to test it
	for (int i = 1; i <= 17; i++)
	{
		// read next entry
		buyerListBin.read(reinterpret_cast<char *>(&buyer), sizeof(buyer));
		cout << left << setw(12)
			<< buyer.buyerName << right << setw(4) << buyer.buyerNum << endl;
		buyerListTXT << left << setw(12) << buyer.buyerName << left << setw(4)
			<< buyer.buyerNum << endl;
	}

	//close files
	buyerListBin.close();
	buyerListTXT.close();

	return 0;
}