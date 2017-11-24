#ifndef DIE_H
#define DIE_H

class Die
{
private:
	int sides;		// number of die sides
	int value;		// the die's value post roll
public:
	Die(int sides = 6);	// constructor defaults to 6 sides
	void roll();	// calls a random number, "rolls" die
	int getSides() const;	// returns the number of sides on die
	int getValue() const; // returns the die's value after roll
};

#endif