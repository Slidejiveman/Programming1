#include <iostream>
#include <iomanip>

using namespace std;

void stackTheCharacters();

void main()
{
	// Direction for the User
	cout << "Please enter a sentence ending with a period."
		<< endl;

	// Call recursive function
	stackTheCharacters();
	cout << endl;
}

//*********************************************************************************************
// stackTheCharacters accepts no arguments and returns no value. It displays the characters   *
// entered into the keyboard if the string ends with a period. As the stack unwinds, it will  *
// display all of the characters in the opposite order they were entered.					  *
// Variables: theCharacter = collected with cin.get from the user, held until stack unwinds   *
// Arguments: None																			  *
// Return:    None																			  *
//*********************************************************************************************
void stackTheCharacters()
{
	// Local variable
	char theCharacter;

	// Read the keyboard entries one at a time
	cin.get(theCharacter);

	// Recursive functions often use if, then, else logic so the loop will stop
	if (theCharacter != '.')					// Condition for the non-recursive call
		stackTheCharacters();					// A recursive call, pauses this function

	// Display the character one at atime.
	cout << theCharacter;						// They are displayed backwards as the
												// Stack unwinds.
}