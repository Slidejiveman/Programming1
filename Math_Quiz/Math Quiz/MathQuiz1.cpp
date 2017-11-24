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
	int number1, number2; //to store random numbers to be added
	int sum; //to store the total after addition
	int answer; //to store the answer provided by the student
	int question = -1; //holds running total of questions asked
	int correct = 0; //counter holding number of correct answers
	float percentCorrect; //holds percentage of student accuracy
	unsigned seed = time(0); //to hold system time and generate truer rands
	const int MIN_VALUE = 1; //to hold the lower end of random number range
	const int MAX_VALUE = 99; //to hold higher end as per instructions

	cout << "Please input your answer and then press the enter key\n";
	srand(seed);

	do
	{
		number1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		number2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

		cout << setw(4) << right << number1 << endl;
		cout << left << "+" << setw(3) << right << number2 << endl;
		cout << right << "____" << endl;

		cin >> answer;
		cin.get();

		//calculate the sum of the two numbers
		sum = number1 + number2;

		if (answer == sum)
		{
			cout << "Great work!\n\n";
			cout << setw(4) << right << "The answer is: " << sum << endl << endl << endl;
			correct++;
		}
		else if (answer != sum && answer != -1)
		{
			cout << "Try again. You can do this!\n\n";
			cout << setw(4) << right << number1 << endl;
			cout << left << "+" << setw(3) << right << number2 << endl;
			cout << right << "____" << endl;
		}
		else
			cout << "Program Terminated.\n\n";

		question++;
	} while (answer != -1);

	cout << "Questions asked: " << question << endl;

	//calculate percent of questions answered correctly
	percentCorrect = static_cast<float>((correct) / question) * 100;

	cout << "Percent of questions answered correctly: " << percentCorrect << "%" << endl;

	return 0;
}