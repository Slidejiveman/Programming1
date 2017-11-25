#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Product
{
	int productNumber;
	char productDescription[20];
	float price;
	int stockQuantity;
	float totalValue;
};

int main()
{
	Product productInfo;
	fstream productFile("lab6task1.dat", ios::in | ios::binary);
	ofstream productTXT("lab6task2.txt");

	//check to see if file opened
	if (productFile.fail())
	{
		cout << "The BINARY file did not open properly.\n";
		return 0;
	}
	if (productTXT.fail())
	{
		cout << "The TEXT file did not open properly.\n";
		return 0;
	}

	//read in from binary file and display contents to cout and .txt
	cout << fixed << showpoint << setprecision(2);
	productTXT << fixed << showpoint << setprecision(2);

	//display header row and write it to .txt file
	cout << left << setw(7) << "Prod.#" << left << setw(25) <<   "Prod. Desc." << right 
		<< setw(8) << "Price" << right << setw(4) << "Q" << right << setw(8) <<  "  T. Val.\n";
	productTXT << left << setw(7) << "Prod.#" << left << setw(25) << "Prod. Desc." << right
		<< setw(8) << "Price" << right << setw(4) << "Q" << right << setw(8) << "  T. Val.\n";
	
	//read from binary file
	productFile.read(reinterpret_cast<char *>(&productInfo), sizeof(productInfo));//prime while
	while (!productFile.eof())
	{
		//display contents of binary file
		cout << left << setw(7) << productInfo.productNumber << left << setw(25) 
			<< productInfo.productDescription << right << setw(8) << productInfo.price 
			<< setw(4) << right << productInfo.stockQuantity << right << setw(8)
			<< productInfo.totalValue << endl;
		productTXT << left << setw(7) << productInfo.productNumber << left << setw(25)
			<< productInfo.productDescription << right << setw(8) << productInfo.price
			<< setw(4) << right << productInfo.stockQuantity << right << setw(8)
			<< productInfo.totalValue << endl;

		//read next record
		productFile.read(reinterpret_cast<char *>(&productInfo), sizeof(productInfo));
	}

	//close files
	productFile.close();
	productTXT.close();

	return 0;
}