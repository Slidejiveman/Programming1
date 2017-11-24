//name, address, and phone number in string variables
#include <iostream>
#include <string> // required for string class
using namespace std;
int main()
{
	string name, address, phone;
	name = "Ryder Dale Walton \n";
	address = "2100 NE 140th Street Apt 203-B \n";
	phone = "580-271-8369 \n\n";

	cout << name << address << phone << endl;
	return 0;
}