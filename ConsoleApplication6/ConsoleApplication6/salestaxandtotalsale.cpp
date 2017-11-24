#include<iostream>
using namespace std;

int main()

{
	float sale, total, tax, taxRate;

	cout << "How much were the items before sales tax?\n";
	cin >> sale;

	cout << "What is the sales tax rate in your area? Enter this value as a decimal.\n";
	cin >> taxRate;

	//calculate  the total cost of the sale.
	total = sale + (sale * taxRate);

	//calculate the tax due on the sale
	tax = sale * taxRate;

	cout << "The total of the sale is " << total << " and the amount of this value going toward taxes is "
		<< tax << endl;

	return 0;
}