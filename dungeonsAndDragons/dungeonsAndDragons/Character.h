#ifndef CHARACTER_H
#define CHARACTER_H

//GLOBAL CONSTANTS
const int MAX_NAME = 41;	// Maximum array name size 

class Character
{
private: 
	int level;				// Holds character's current level
	int experiencePoints;	// Holds experience points earned
	char name[MAX_NAME];	// Allows a name of 40 characters + null
	int age;				// holds any age

public: 
	// Constructors
	Character(int lvl = 1, int exp = 0);		// Default constructor

	// Mutator functions
	void setLevel(int lvl);			// Sets character level
	void setExperience(int exp);	// Adds experience points to total
	void setName(char name[]);		// Puts given name into name variable
	void setAge(int years);			// Puts age into the age variable

	// Accessor functions
	int getLevel() const;			// Returns characters current level
	int getExperience() const;		// Returns experience point total
	char getName() const;			// Returns character's name
	int getAge() const;				// Returns the age variable
};

#endif