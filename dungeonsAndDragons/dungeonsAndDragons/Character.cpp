#include "Character.h"
#include <cstring>
#include <cctype>

using namespace std;

/*MUTATORS*/

//***************************************************************
// The constructor accepts an argument for character's start level
// as well as current number of experience points.
//***************************************************************
Character::Character(int lvl, int exp)
{
	//set private values to defaults
	level = lvl;
	experiencePoints = exp;
}

//***************************************************************
// The setLevel function sets the character's level by overwriting
// the value currently held in level. Accepts an int. No return value.
//***************************************************************
void Character::setLevel(int lvl)
{
	level = lvl;
}

//***************************************************************
// The addExperience function works just as the setLevel function.
// The only difference is that it overwrites the value held in the
// experiencePoints variable. Accepts an int. No return value.
//***************************************************************
void Character::setExperience(int exp)
{
	experiencePoints = exp;
}

//***************************************************************
// The setName function uses string copy to assign the given name
// to the character. Accepts an array of characters. No return value.
//***************************************************************
void Character::setName(char charName[MAX_NAME])
{
	strcpy_s(name, charName);
}

//***************************************************************
// The setAge function assigns the given character age to the
// character object. Accepts an integer. No return value.
//***************************************************************
void Character::setAge(int years)
{
	age = years;
}


/*ACCESSORS*/


//***************************************************************
// The getLevel function returns an integer representing the 
// character object's current level.
//***************************************************************
int Character::getLevel() const
{
	return level;
}

//***************************************************************
// The getExperience function returns and integer representing the
// character object's current horde of experience points.
//***************************************************************
int Character::getExperience() const
{
	return experiencePoints;
}
//***************************************************************
// The getName function returns the character's name, which is
// stored as character types.
//***************************************************************
char Character::getName() const
{
	return name[MAX_NAME];
}

//***************************************************************
// The getAge function returns an integer representing the age of
// the character object in terms of human years.
//***************************************************************
int Character::getAge() const
{
	return age;
}