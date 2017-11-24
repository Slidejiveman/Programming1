#include <iostream>
using namespace std;

const int SIZE = 3;

void displayBoard(char[][SIZE]);
void checkValid(char[][SIZE], int&, int&);
bool winner(char[][SIZE]);

int main()
{
	char xOrO[SIZE][SIZE] = { { '*', '*', '*'},
						{ '*', '*', '*'},
						{'*', '*', '*'} };
	char turn = 'O';
	int row, column;
	bool endGame;
	int tie = 0;

	do
	{
		if (turn == 'O')//swap the turn every pass
			turn = 'X';
		else
			turn = 'O';

		cout << "Go " << turn << endl;
		cin >> row >> column;
		
		//determine whether or not the space is occupied
		checkValid(xOrO, row, column);
		
		xOrO[row][column] = turn;//replaces a star with the value stored in turn during a given iteration.
		
		displayBoard(xOrO);//displays the stars
		
		endGame = winner(xOrO);//checks all possible victories for X and O and returns a bool

		//enrage counter: ends game if nine iterations of the loop occur
		tie++;
		if (tie == 9)
			cout << "Draw.\n";

	} while (!endGame);// this changes the false value to a true and the loop continues, or makes a true value false and we fall out

	cout << turn << "is the winner!";

	return 0;
}

void displayBoard(char xOrO[][SIZE])
{
	for (int r = 0; r < SIZE; r++)
	{
		for (int c = 0; c < SIZE; c++)
		{
			cout << xOrO[r][c] << " ";
		}
		cout << "\n\n";
	}	
}

void checkValid(char xOrO[][SIZE], int& row, int& column)
{
	while (xOrO[row][column] == 'X' || xOrO[row][column] == 'O')
	{
		cout << "There is already a piece there. Try again.\n";
		cin >> row >> column;
	}
}

bool winner(char xOrO[][SIZE])
{
	bool winner = false;

	//horizontal victories
	if (xOrO[0][0] == 'X' && xOrO[0][1] == 'X' && xOrO[0][2] == 'X')
		winner = true;
	else if (xOrO[1][0] == 'X' && xOrO[1][1] == 'X' && xOrO[1][2] == 'X')
		winner = true;
	else if (xOrO[2][0] == 'X' && xOrO[2][1] == 'X' && xOrO[2][2] == 'X')
		winner = true;

	//vertical victories
	if (xOrO[0][0] == 'X' && xOrO[1][0] == 'X' && xOrO[2][0] == 'X')
		winner = true;
	else if (xOrO[0][1] == 'X' && xOrO[1][1] == 'X' && xOrO[2][1] == 'X')
		winner = true;
	else if (xOrO[0][2] == 'X' && xOrO[1][2] == 'X' && xOrO[2][2] == 'X')
		winner = true;
	
	//diagnonal victories
	if (xOrO[0][0] == 'X' && xOrO[1][1] == 'X' && xOrO[2][2] == 'X')
		winner = true;
	else if (xOrO[0][2] == 'X' && xOrO[1][1] == 'X' && xOrO[2][0] == 'X')
		winner = true;

	//horizontal victories
	if (xOrO[0][0] == 'O' && xOrO[0][1] == 'O' && xOrO[0][2] == '0')
		winner = true;
	else if (xOrO[1][0] == 'O' && xOrO[1][1] == 'O' && xOrO[1][2] == 'O')
		winner = true;
	else if (xOrO[2][0] == 'O' && xOrO[2][1] == 'O' && xOrO[2][2] == 'O')
		winner = true;

	//vertical victories
	if (xOrO[0][0] == 'O' && xOrO[1][0] == 'O' && xOrO[2][0] == 'O')
		winner = true;
	else if (xOrO[0][1] == 'O' && xOrO[1][1] == 'O' && xOrO[2][1] == 'O')
		winner = true;
	else if (xOrO[0][2] == 'O' && xOrO[1][2] == 'O' && xOrO[2][2] == 'O')
		winner = true;

	//diagnonal victories
	if(xOrO[0][0] == 'O' && xOrO[1][1] == 'O' && xOrO[2][2] == 'O')
		winner = true;
	else if (xOrO[0][2] == 'O' && xOrO[1][1] == 'O' && xOrO[2][0] == 'O')
		winner = true;
	
	
	//loops would work if i hadn't initialized asterisks
	//I've only kept this here for my own personal reference.

	/*for (int row = 0; row < SIZE; row++)
	{
		if (xOrO[row][0] == xOrO[row][1] && xOrO[row][1] == xOrO[row][2])
			winner = true;
	}

	for (int column = 0; column < SIZE; column++)
	{
		if (xOrO[0][column] == xOrO[1][column] && xOrO[1][column] == xOrO[2][column])
			winner = true;
	}*/

return winner;
}