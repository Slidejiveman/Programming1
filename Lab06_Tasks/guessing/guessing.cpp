#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int number;
	int guess = 0;
	int numberOfGuesses = 1;
	unsigned seed = time(0); 
	const int MIN_VALUE = 1; 
	const int MAX_VALUE = 10; 

	srand(seed);

	number = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	
	cout << "I'm thinking of a number between 1 and 10. Can you guess it?\n";
	
	while (guess != number)
	{
		cin >> guess;

		if (guess > number)
			cout << "Too high, try again.\n";
		else if (guess < number)
			cout << "Too low, try again.\n";
		else if (guess == number)
		{
			cout << number << " is exactly right!\n";
			cout << "It took you " << numberOfGuesses << " guess(es)!\n";
		}
		numberOfGuesses++;
	}
	return 0;
}