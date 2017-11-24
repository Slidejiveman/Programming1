#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

struct TransactionType
{
	char itemID[7];
	int buyerNum;
	float amount;
};

int main()
{
	TransactionType transaction;		//instance of struct

	//open file streams
	ofstream transactionListTXT("trans_list.txt");
	fstream transactionListBin("translist.dat", ios::out | ios::binary);

	//check for successful open
	if (transactionListTXT.fail())
	{
		cout << "The TEXT file did not open properly.\n";
		exit(0);
	}
	if (transactionListBin.fail())
	{
		cout << "The BINARY file did not open properly.\n";
		exit(0);
	}

		//collect data from the keyboard
		for (int i = 1; i <= 28; i++)
		{
			cout << "Enter the item ID in AANNN format\n";
			cin.getline(transaction.itemID, 7);
			cout << "Enter the buyer number\n";
			cin >> transaction.buyerNum;
			cout << "Enter the amount paid\n";
			cin >> transaction.amount;
			cin.ignore();
			transactionListBin.write(reinterpret_cast<char *>(&transaction), sizeof(transaction));
			// test cout
			cout << transaction.itemID << " " << transaction.buyerNum << " " 
				<< transaction.amount << endl;
		}
		
	//read in contents of binary file and write them to txt file 
	cout << fixed << showpoint << setprecision(2);
	transactionListTXT << fixed << showpoint << setprecision(2);
	cout << "Item ID" << " Buyer Num" << " Amount \n\n";
	transactionListTXT << "Item ID" << " Buyer Num" << " Amount \n\n";

	//close and reopen file for input
	transactionListBin.close();
	transactionListBin.open("translist.dat", ios::in | ios::binary);

	//read in from binary file to test it
	for (int i = 1; i <= 28; i++)
	{
		// read next entry
		transactionListBin.read(reinterpret_cast<char *>(&transaction), sizeof(transaction));
		cout << left << setw(10)
			<< transaction.itemID << left << setw(10) << transaction.buyerNum
			<< right << setw(5) << transaction.amount << endl;
		transactionListTXT << left << setw(10)
			<< transaction.itemID << left << setw(10) << transaction.buyerNum
			<< right << setw(5) << transaction.amount << endl;
	}

	//close files
	transactionListBin.close();
	transactionListTXT.close();

	return 0;
}