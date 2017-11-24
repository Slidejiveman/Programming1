#include <iostream>
using namespace std;


int main()
{

	int number; //entered by user, base number for factorial
	int total = 1; //to keep track of the factorial so far

	cout << "Enter the number for which you desire to see a factorial\n";
	cin >> number;

	for (number; number > 0; number--)
	{
		total = total * number;
	}

	cout << total;
	return 0;
}