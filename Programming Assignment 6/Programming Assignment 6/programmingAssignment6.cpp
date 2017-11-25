//====================================================================
// Ryder Dale Walton
//11-10-14
//Programming Assignment #6
//Description: Exam Grader
//====================================================================

/*This program compares a master set of correct exam answers that is
compared against an entire class' answers. It then displays the grade
and the questions missed.*/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//global constants
const int SIZE = 20;//so that functions can be useful for different arrays

//function prototypes
void getCorrectAnswers(char[], int);
void getStudentAnswers(char[], char[], int);
void compareAnswers(string, char[], char[], int);
int calculatePercentCorrect(int, int);
bool isPerfectScore(char[], char[], int);

int main()
{
	//variable declarations
	char correctAnswers[SIZE];//array holding answer key
	char studentAnswers[SIZE];//array holding student answers to check

	//open file and read answer key into array
	getCorrectAnswers(correctAnswers, SIZE);

	//open file and read student answers into an array
	getStudentAnswers(studentAnswers, correctAnswers, SIZE);

	return 0;
}

void getCorrectAnswers(char correctAnswers[], int SIZE)
{
	ifstream inputAnswerKey;//to open answer key file
	int count = 0;//counter for loop reading file elements into array
	inputAnswerKey.open("CorrectAnswers.txt");
	
	//check for succesful open
	if (inputAnswerKey)
	{
		//read file into array elements
		while (count < SIZE && inputAnswerKey >> correctAnswers[count])
			count++;
		inputAnswerKey.close();
	}
	else
		cout << "CorrectAnswers.txt did not open.\n";
}

void getStudentAnswers(char studentAnswers[], char correctAnswers[], int SIZE)
{
	string studentName;//to separate string name from char answers
	ifstream inputStudentAnswers;//to open student answer file

	inputStudentAnswers.open("StudentAnswers.txt");

	//check for successful open
	if (inputStudentAnswers)
	{
		//read names into strings, read chars into array
		while (inputStudentAnswers >> studentName)
		{
			for (int count = 0; count < SIZE && inputStudentAnswers >> studentAnswers[count]; count++)
			{//empty body. This is the end of the loop. (Null for loop).
			}
			compareAnswers(studentName, correctAnswers, studentAnswers, SIZE);
		}
		inputStudentAnswers.close();
	}
	else
		cout << "StudentAnswers.txt did not open.\n";
}

void compareAnswers(string studentName, char correctAnswers[], char studentAnswers[], int SIZE) 
{
	int percentCorrect;//displays the truncated percentage of correct answers given
	int question = 1;//holds number of question for cout
	int correctAnswer = 0;//holds number of correctly answered questions
	bool perfectScore;//bool that receives value of isPerfectScore function


	//begin displaying output
	cout << "=========================\n"
		<< "Student Name: " << studentName << endl
		<< "Missed Questions: \n";

	//test to see if score is perfect. This changes the headers.
	perfectScore = isPerfectScore(correctAnswers, studentAnswers, SIZE);
	if (perfectScore)
	{
		cout << "None\n";
		correctAnswer = SIZE;
	}
	else
	{
		cout << "Questions   Given   Correct\n";
		//display missed question number and correct answer
		for (int count = 0; count < SIZE; count++)
		{
			if (correctAnswers[count] != studentAnswers[count])
			{
				cout << setw(2) << question
					<< setw(12) << correctAnswers[count]
					<< setw(10) << studentAnswers[count] << endl;
			}
			else
				correctAnswer++;

			question++;
		}
	}
	//calculate percent correct
	percentCorrect = calculatePercentCorrect(correctAnswer, SIZE);

	if (percentCorrect > 60)
		cout << "Passed (" << percentCorrect << "% Correct)\n";
	else
		cout << "Failed (" << percentCorrect << "% Correct)\n";
}

int calculatePercentCorrect(int correctAnswer, int SIZE)
{
	int percentCorrect = (static_cast<float>(correctAnswer) / SIZE) * 100;
	return percentCorrect;
}

bool isPerfectScore(char correctAnswers[], char studentAnswers[], int SIZE)
{
	bool perfectScore = true;//local variable to tell whether arrays are equal

	for (int count = 0; count < SIZE; count++)
	{
		if (correctAnswers[count] != studentAnswers[count])
		{
			perfectScore = false;
		}
	}
	return perfectScore;
}