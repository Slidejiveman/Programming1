//====================================================================
// Ryder Dale Walton
//10-10-14
//Programming Assignment #4
//Description: Math Quiz
//====================================================================

/*This program expands the previous math tutor program by adding a loop,
which allows the program to run time and again. Furthermore, this program
tracks the number of questions asked, accuracy as a percent, and also provides
feedback to the student.*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()

{
	int number1, number2; //to store random numbers for addition
	int number3; //to store the random numbers used to choose couts
	int sum; //stores total after addition
	int answer; //to store the answer provided by the student
	int question = 0; //holds running total of questions asked
	int correct = 0; //counter holding number of correct answers
	float percentCorrect; //holds percentage of student accuracy
	unsigned seed = time(0); //to hold system time for rands
	const int MIN_VALUE = 1; //to hold minimum number for both ranges
	const int MAX_VALUE_B = 4; //to hold the maximum rand for feedback
	const int MAX_VALUE_A = 99; //to hold maximum possible addition n umber

	cout << "Please input your answer and then press the enter key\n";
	srand(seed);

	number1 = (rand() % (MAX_VALUE_A - MIN_VALUE + 1)) + MIN_VALUE;
	number2 = (rand() % (MAX_VALUE_A - MIN_VALUE + 1)) + MIN_VALUE;

	cout << setw(4) << right << number1 << endl;
	cout << left << "+" << setw(3) << right << number2 << endl;
	cout << right << "____" << endl;

	cin >> answer;

	while (answer != -1)
	{

		//calculate the sum of the two numbers
		sum = number1 + number2;

		if (answer == sum)
		{
			cout << setw(4) << right << "The answer is: " << sum << endl;
			correct++;
			
			//use random numbers to determine feedback response
			number3 = (rand() % (MAX_VALUE_B - MIN_VALUE + 1)) + MIN_VALUE;
			if (number3 == 1)
				cout << "Great work!\n\n";
			else if (number3 == 2)
				cout << "Excellent.\n\n";
			else if (number3 == 3)
				cout << "Righteous!\n\n";
			else
				cout << "Inconceivable!!!\n\n";

			number1 = (rand() % (MAX_VALUE_A - MIN_VALUE + 1)) + MIN_VALUE;
			number2 = (rand() % (MAX_VALUE_A - MIN_VALUE + 1)) + MIN_VALUE;
			
		}
		else 
		{
			//use random numbers to determine feedback response
			number3 = (rand() % (MAX_VALUE_B - MIN_VALUE + 1)) + MIN_VALUE;
			if (number3 == 1)
				cout << "Try again. You can do this!\n\n";
			else if (number3 == 2)
				cout << "You silly little (wo)man.\n\n";
			else if (number3 == 3)
				cout << "Ridiculous!\n\n";
			else
				cout << "Do you speak to your mother with that math???\n\n";
		}
		cout << setw(4) << right << number1 << endl;
		cout << left << "+" << setw(3) << right << number2 << endl;
		cout << right << "____" << endl;

		cin >> answer;
		
		question++;
	}

	cout << "Questions asked: " << question << endl;

	//calculate percent of questions answered correctly
	percentCorrect = (static_cast<float>(correct) / question) * 100;

	cout << fixed << showpoint << setprecision(2);
	cout << "Percent of questions answered correctly: " << percentCorrect << "%" << endl;

	return 0;
}