#include<iostream>
#include<string>
using namespace std;

int main()

{
	string address;

	cout << "What is your address?";
	getline(cin, address);

	cout << address << " is your address?! Mine too!\n";

	return 0;
}