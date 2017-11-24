#include <iostream>
using namespace std;

int main()
{
	int plusColumn, plusRow;

	for (plusRow = 1; plusRow <= 10; plusRow++)
	{
		for (plusColumn = 1; plusColumn <= plusRow; plusColumn++)
			cout << "+";
		cout << endl;
	}

	for (plusRow = 10; plusRow >= 1; plusRow--)
	{
		for (plusColumn = 1; plusColumn <= plusRow; plusColumn++)
			cout << "+";
		cout << endl;
	}

	return 0;
}