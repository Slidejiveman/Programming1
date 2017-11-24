#include <iostream>			// Allows output to screen
#include <fstream>			// Prints status sheets
#include <cstring>			// Since C-Strings are used
#include <cctype>			// Since C-Strings are used
#include "Die.h"			// All dice functions
#include "Character.h"		// All character functions

using namespace std;

//*************************************************************
// PROGRAM INFORMATION:
// The purpose: 
// To simulate a Dungeons and Dragons campaign session. D20Mod
// is the particular version in mind.
// The flow:
// the main menu is displayed, the sub menu is displayed until
// the user decides to return to the main menu to either quit
// the session or navigate to another sub menu.
// Future plans:
// To add equipment tracking, character stat tracking, and 
// battle simulation
//*************************************************************

// CONSTANTS
//**************************************************************
Die D20(20);				// twenty-sided die
Die D12(12);				// twelve-sided die
Die D10(10);				// ten-sided die
Die PERCENT_EFFECTIVE(100);	// percentage success die
Die D8(8);					// eight-sided die
Die D6;						// six-sided die
Die D4(4);					// four-sided die
Die D2(2);					// quarter flip
Character PLAYER;			// holds all character stats

// FUNCTION PROTOTYPES
//**************************************************************
bool mainMenu();
bool dieMenu();
bool characterMenu();
//bool equipmentMenu();

//**************************************************************
// Main is the spine of the program. It's primary function is to
// call mainMenu in a do-while loop.
//**************************************************************

int main()
{
	// VARIABLE DECLARATIONS
	//**********************************************************
	bool keepPlaying = true;			// controls main loop

	// GAME LOOP
	//*********************************************************
	cout << "Welcome to Dungeons and Dragons! May the odds be "
		<< "ever in your favor!\n\n";
	
	// Display main menu until bool exits the loop
	do
	{
		keepPlaying = mainMenu();
	} while (keepPlaying);

	cout << "Thanks for playing! I hope you will return to your "
		<< "journey soon, adventurer. \n";

	// RETURN VALUE
	//*********************************************************
	return 0;

}

//**************************************************************
// mainMenu displays the umbrella options 
// available to the user. It is the core menu, returns a bool
// that main uses to determine whether or not the session is over.
//**************************************************************
bool mainMenu()
{
	// VARIABLE DECLARATIONS
	//**********************************************************
	bool keepPlaying = true;	// either play or exit program
	int menuChoice;				// determines option

	// MAIN MENU LOOP
	//*********************************************************
	do
	{
		// I/O interface
		cout << "Main Menu: \n\n"
			<< "1. Roll Dice\n"
			<< "2. Enter Equipment\n"
			<< "3. Character Statistics\n"
			<< "4. Battle Simulation Options\n"
			<< "0. Quit\n\n Selection: ";
		cin >> menuChoice;

		// DECISION CENTER
		// If option 1 is selected, call die menu.
		if (menuChoice == 1)
			dieMenu();
		// At present, options 2 & 4 are not ready.
		else if (menuChoice == 2 || menuChoice == 4)
			cout << "These features are coming soon!\n\n";
		else if (menuChoice == 3)
			characterMenu();
		// If 0 is selected, the program ends.
		else if (menuChoice == 0)
			keepPlaying = false;
		else
		// Input validation statement.
			cout << "That was not a valid input. Please choose again.\n\n";
	} while (keepPlaying);

	// RETURN VALUE
	//*********************************************************
	return keepPlaying;
}

//**************************************************************
// dieMenu gives the user all of the available roll options.
// It returns a bool determining whether or not to keep rolling.
// when false, this returns the user to the main menu.
//**************************************************************
bool dieMenu()
{
	// VARIABLE DECLARATIONS
	//*********************************************************
	int menuChoice;				// handles user selections
	bool keepRolling = true;	// assumes true, exits loop when false

	// DIE MENU LOOP
	//*********************************************************
	do
	{
		// I/O interface
		cout << "Die Selection Menu: \n\n"
			<< "1. Roll d20\n"
			<< "2. Roll d12\n"
			<< "3. Roll d10\n"
			<< "4. Roll d8\n"
			<< "5. Roll d6\n"
			<< "6. Roll d4\n"
			<< "7. Roll Percent Effective Die\n"
			<< "8. Flip a coin\n"
			<< "0. return to Main Menu\n\n Selection: ";
		cin >> menuChoice;

		//DECISION CENTER
		// if option 1 is selected, call die menu
		if (menuChoice == 1)
		{
			D20.roll();
			cout << endl << "You rolled: " << D20.getValue() << endl << endl;
		}
		// at present, options 2-4 are not ready.
		else if (menuChoice == 2)
		{
			D12.roll();
			cout << endl << "You rolled: " << D12.getValue() << endl << endl;
		}
		else if (menuChoice == 3)
		{
			D10.roll();
			cout << endl << "You rolled: " << D10.getValue() << endl << endl;
		}
		else if (menuChoice == 4)
		{
			D8.roll();
			cout << endl << "You rolled: " << D8.getValue() << endl << endl;
		}
		else if (menuChoice == 5)
		{
			D6.roll();
			cout << endl << "You rolled: " << D6.getValue() << endl << endl;
		}
		else if (menuChoice == 6)
		{
			D4.roll();
			cout << endl << "You rolled: " << D4.getValue() << endl << endl;
		}
		else if (menuChoice == 7)
		{
			PERCENT_EFFECTIVE.roll();
			cout << endl << "You rolled: " << PERCENT_EFFECTIVE.getValue() 
				<< endl << endl;
		}
		else if (menuChoice == 8)
		{
			D2.roll();
			if (D2.getValue() == 1)
				cout << endl << "You rolled: 1. It's heads! \n\n";
			else
				cout << endl << "You rolled: 2. It's tails! \n\n";
		}
		// if 0 is selected, the program returns to main menu.
		else if (menuChoice == 0)
			keepRolling = false;
		else
		// input validation
			cout << "that was not a valid input. Please choose again.\n\n";

	} while (keepRolling);

	// RETURN VALUE
	//*********************************************************
	return keepRolling;
}

//**************************************************************
// equipmentMenu will allow the user to enter currently held 
// equipment into the system. I might make an object to track
// the various kinds of equipment too
//**************************************************************
//bool showEquipmentMenu()
//{
//
//}

//**************************************************************
// characterMenu allows the user to set up his/her character with
// either the default values, or the values representating where
// the prior session of the game ended.
//**************************************************************
bool characterMenu()
{
	// VARIABLE DECLARATIONS
	//*********************************************************
	// Keeps reads in and out the character status
	fstream characterStats("characterStats.txt", ios::in | ios::out | ios::app);
	int menuChoice;				// handles user selections
	bool keepEntering = true;	// assumes true, exits loop when false
	int lvl;					// local variable holding character level
	int exp;					// local variable holding character exp
	char charName[MAX_NAME];	// local array holding character name
	int years;					// local variable holding character age

	// Check file stream object for succesful open
	if (characterStats.fail())
	{
		cout << "The file didn't open properly.\n";
		exit(0);
	}

	// CHARACTER MENU LOOP
	//*********************************************************
	do
	{
		// I/O interface
		cout << "Character Menu: \n\n"
			<< "1. Enter Name\n" 
			<< "2. Set Level\n"
			<< "3. Set Experience Points\n"
			<< "4. Set Age\n"
			<< "10. Read from file\n"
			<< "11. Display stats\n"
			<< "0. Back to Main Menu\n\n Selection: ";
		cin >> menuChoice;

		// DECISION CENTER
		// If option 1, the character's name is entered.
		if (menuChoice == 1) // NOT WORKING; MIGHT ASK FOR NUMBER OF CHARS TO FIX
		{
			cout << "Enter your characters name in less than 40 characters.\n";
			cin.getline(charName, MAX_NAME);			
			PLAYER.setName(charName);
		}
		// Option 2 sets the character's level.
		else if (menuChoice == 2)
		{
			cout << "Enter your character's level as an integer.\n";
			cin >> lvl;
			PLAYER.setLevel(lvl);
		}
		// Option 3 sets your character's experience
		else if (menuChoice == 3)
		{
			cout << "Enter your character's amassed exp as an integer.\n";
			cin >> exp;
			PLAYER.setExperience(exp);
		}
		// Option 4 sets the character's age
		else if (menuChoice == 4)
		{
			cout << "Enter your character's age as an integer.\n";
			cin >> years;
			PLAYER.setAge(years);
		}
		// Option 10 allows the stats to be read in from a formatted file
		else if (menuChoice == 10)
		{
			// Read file in		NOT WORKING
			characterStats >> charName >> lvl >> exp >> years;

			// Set data
			PLAYER.setName(charName);
			PLAYER.setLevel(lvl);
			PLAYER.setExperience(exp);
			PLAYER.setAge(years);
		}
		// Option 11 displays all of the statistics currently entered
		else if (menuChoice == 11)
		{
			// Display info on console screen
			cout << endl << "Character Name: " << PLAYER.getName() << endl;
			cout << "Level: " << PLAYER.getLevel() << endl;
			cout << "Exp: " << PLAYER.getExperience() << endl;
			cout << "Age: " << PLAYER.getAge() << endl << endl;

			// Write data to text file
			characterStats << PLAYER.getName() << " ";
			characterStats << PLAYER.getLevel() << " ";
			characterStats << PLAYER.getExperience() << " ";
			characterStats << PLAYER.getAge() << " ";
			
		}
		// If 0 is selected, the program ends.
		else if (menuChoice == 0)
			keepEntering = false;
		else
			// Input validation statement.
			cout << "That was not a valid input. Please choose again.\n\n";

	} while (keepEntering);

	// Close File Stream Object
	characterStats.close();

	// RETURN VALUE
	//*********************************************************
	return keepEntering;
}