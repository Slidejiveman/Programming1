#include <iostream>
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
	fstream productFile("lab6task1.dat", ios::binary | ios::out);
	ofstream productTXT("lab6task1.txt");
	
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

	//allow data to be entered from the keyboard
	for (int i = 0; i < 6; i++)
	{
		cout << "Please input the product number.\n";
		cin >> productInfo.productNumber;
		cout << "Next, input the product description.\n";
		cin.ignore(); //skip the return in the keyboard buffer
		cin.getline(productInfo.productDescription, 20);
		cout << "What is the price of the item? \n";
		cin >> productInfo.price;
		cout << "How many of these items are in stock?\n";
		cin >> productInfo.stockQuantity;

		//calculate the Total Value
		productInfo.totalValue = productInfo.price * productInfo.stockQuantity;
		
		//write contents to the file
		productFile.write(reinterpret_cast<char *>(&productInfo), sizeof(productInfo));

		//cout what is held for test purposes
		cout << productInfo.productNumber << " " << productInfo.productDescription
			<< productInfo.price << productInfo.stockQuantity
			<< productInfo.totalValue << endl;
	}

	//close files
	productFile.close();
	productTXT.close();

	return 0;
}