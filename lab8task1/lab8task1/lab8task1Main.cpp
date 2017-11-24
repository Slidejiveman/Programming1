#include "traffic.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//declarations
	ofstream lab8Output("lab8Output.txt", ios::app);
	Traffic Yosemite;

	// test file open
	if (lab8Output.fail())
	{
		cout << "The file did not open!\n";
		exit(0); // if the file does not open, abort the program
	}

	//Test 1
	cout << "Test 1: Cars/People enter park. No thresholds crossed.\n"
		<< "Expecting no output. I am allowing 9,999 cars and 29,999 people enter.\n\n";
	lab8Output << "Test 1: Cars/People enter park. No thresholds crossed.\n\n"
		<< "Expecting no output. I am allowing 9,999 cars and 29,999 people enter.\n\n";

	Yosemite.enter(9995, 29999);

	//Test 2 
	cout << "Test 2: Cars/People enter park. People threshold is exceeded but car threshold is not\n."
		<< "Enter should display appropriate warning. I am allowing 2 cars and 6 people to enter\n\n";
	lab8Output << "Test 2: Cars/People enter park. People threshold is exceeded but car threshold is not\n."
		<< "Enter should display appropriate warning. I am allowing 2 cars and 6 people to enter\n\n";

	Yosemite.enter(2, 6);

	//Test 3
	cout << "Test 3: Cars/People leave park. No thresholds are crossed\n."
		<< "Expecting no output. I am allowing 2 cars and 2 people to leave.\n\n";
	lab8Output << "Test 3: Cars/People leave park. No thresholds are crossed\n."
		<< "Expecting no output. I am allowing 2 cars and 2 people to leave.\n\n";

	Yosemite.exit(2, 2);

	//Test 4
	cout << "Test 4: Cars/People leave park. Only people drop below threshold.\n"
		<< "Exit displays the people message. Two cars are leaving and 6 people are leaving.\n";
	lab8Output << "Test 4: Cars/People leave park. Only people drop below threshold.\n"
		<< "Exit displays the people message. Two cars are leaving and 6 people are leaving.\n";

	Yosemite.exit(2, 6);

	//Test 5
	cout << "Test 5: Cars/People leave park. Cars and people are both above before hand, and this call leaves "
		<< " people above, but cars drops below. \n Car message should be displayed. \n" 
		<< "100 cars and 10 people leave \n\n";
	lab8Output << "Test 5: Cars/People leave park. Cars and people are both above before hand, and this call leaves "
		<< " people above, but cars drops below. \n Car message should be displayed.\n"
		<< "100 cars and 10 people leave \n\n";

	cout << "The enter call here sets up the next test conditions.\n\n";
	lab8Output << "The enter call here sets up the next test conditions.\n\n";
	
	Yosemite.enter(100, 100);

	cout << "Below is the test output.\n";
	lab8Output << "Below is the test output.\n";

	Yosemite.exit(100, 10);

	//Test 6
	cout << "Test 6: Cars/People leave the park. Cars and people are both above before hand, and this call leaves \n"
		<< "both above. \n There should be no output.\n 1 car and 1 person leave.\n\n";
	lab8Output << "Test 6: Cars/People leave the park. Cars and people are both above before hand, and this call leaves \n"
		<< "both above. \n There should be no output.\n 1 car and 1 person leave.\n\n";

	cout << "This is a dummy run to set up the subsequent test\n\n";
	lab8Output << "This is a dummy run to set up the subsequent test\n\n";
	
	Yosemite.enter(100, 90);

	cout << "The following blank demonstrates that there was no test output.\n";
	lab8Output << "The following blank demonstrates that there was no test outuput.\n";

	Yosemite.exit(1, 1);

	//Test 7
	cout << "Test 7: Cars/People leave park. Cars and people are both above before hand, and this call causes both \n"
		<< "to fall below their thresholds. \n Both messages should be displayed. \n"
		<< "5000 cars and 10000 people leave\n\n";
	lab8Output << "Test 7: Cars/People leave the park. Cars and people are both above before hand, and this call leaves \n"
		<< "both above. \n There should be no output.\n"
		<< "5000 cars and 10000 people leave.\n\n";

	Yosemite.exit(5000, 10000);

	//close the file
	lab8Output.close();

	return 0;
}