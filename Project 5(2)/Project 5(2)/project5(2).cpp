//====================================================================
// Ryder Dale Walton
//10-29-14
//Programming Assignment #5
//Description: Math Drill with Functions
//====================================================================

/*This program modifies assignment 4 by adding in functions for simplicity
and greater variety of when calling random numbers. Additionally, this
program adds multiplication problems to the mix.*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//function prototypes
int generateRand(int, int);
int displayQuestion(int, int, int);
void displayRight(int);
void displayWrong(int);


int main()

{
	int solution; //stores total after addition
	int answer; //to store the answer provided by the student
	int question = 0; //holds running total of questions asked
	int correct = 0; //counter holding number of correct answers
	float percentCorrect; //holds percentage of student accuracy
	unsigned seed = time(0); //to hold system time for rands
	int number1 = generateRand(1, 10); //first number to pass display
	int number2 = generateRand(1, 10);//second to pass display
	int questionType;//third to pass disply, determines question type
	
	srand(seed);

	cout << "Please input your answer and then press the enter key\n";
	number1 = generateRand(1, 10);
	number2 = generateRand(1, 10);
	questionType = generateRand(1, 2);
	solution = displayQuestion(number1, number2, questionType);
	cin >> answer;

	while (answer != -1)
	{
		if (answer == solution)
		{
			cout << setw(4) << right << "The answer is: " << solution << endl;
			correct++;
			displayRight(generateRand(1, 4));
			
			number1 = generateRand(1, 10);
			number2 = generateRand(1, 10);
			questionType = generateRand(1, 2);
		
		}
		else
		{
			displayWrong(generateRand(1, 4));
		}

		solution = displayQuestion(number1, number2, questionType);

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

//function that creates all random numbers
int generateRand(int minimumNumber, int maximumNumber)
{
	int randomNumber = (rand() % (maximumNumber - minimumNumber + 1)) + minimumNumber;

	return randomNumber;
}

//function that generates the question and displays it
int displayQuestion(int number1, int number2, int questionType)
{
	int solution; //holds the value to be returned


	if (questionType == 1)
	{
		cout << setw(4) << right << number1 << endl;
		cout << left << "+" << setw(3) << right << number2 << endl;
		cout << right << "____" << endl;

		solution = number1 + number2;
	}
	else
	{
		cout << setw(4) << right << number1 << endl;
		cout << left << "*" << setw(3) << right << number2 << endl;
		cout << right << "____" << endl;

		solution = number1 * number2;
	}

	return solution;
}

//use random numbers to determine correct feedback response;
void displayRight(int randomNumber)
{
	if (randomNumber == 1)
		cout << "Great work!\n\n";
	else if (randomNumber == 2)
		cout << "Excellent.\n\n";
	else if (randomNumber == 3)
		cout << "Righteous!\n\n";
	else
		cout << "Inconceivable!!!\n\n";
}

//use random numbers to determine incorrect feedback response;
void displayWrong(int randomNumber)
{
	if (randomNumber == 1)
		cout << "Try again. You can do this!\n\n";
	else if (randomNumber == 2)
		cout << "You silly little (wo)man.\n\n";
	else if (randomNumber == 3)
		cout << "Ridiculous!\n\n";
	else
		cout << "Do you speak to your mother with that math???\n\n";
}