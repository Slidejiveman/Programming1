#include <iostream>

using namespace std;

int factorial(int num);

void main()
{
	int number;

	cout << "Enter a number to be solved factorially.\n";
	cin >> number;

	cout << factorial(number) << endl;
}

int factorial(int num)
{
	if (num < 1)
	{
		return 1;
	}
	else return num * factorial(num - 1);
}