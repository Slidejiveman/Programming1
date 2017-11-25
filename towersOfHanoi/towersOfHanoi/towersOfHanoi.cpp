// Towers of Hanoi
#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
void moveDiscs(int startPeg, int endPeg, int storagePeg, int num);

void main()
{
	int number;				// Number of discs to move

	cout << "How many discs do you want to move?\n";
	cin >> number;
	moveDiscs(1, 3, 2, number);
}

// Recursive program that accepts the starting location of the
// discs, the storage location, and the ending location as well.
// Additionally, it accepts a number entered from the keyboard.
void moveDiscs(int startPeg, int endPeg, int storagePeg, int num)
{
	if (num == 1)
	{
		// To make this a graphics program, modify the couts
		cout << "Move disc from peg " << startPeg << " to peg "
			<< endPeg << endl;
	}
	else
	{
		moveDiscs(startPeg, storagePeg, endPeg, (num - 1));
		cout << "Move disc from peg " << startPeg << " to peg "
			<< endPeg << endl;
		moveDiscs(storagePeg, endPeg, startPeg, (num - 1));
	}
}