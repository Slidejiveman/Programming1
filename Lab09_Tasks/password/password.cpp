#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int SIZE = 50;

int fileRead(string[], string[], int);
void sort(string[], string[], int);
int binarySearch(const string[], string, int);

int main()
{
	string username[SIZE];//set to worst case capacity
	string password[SIZE];
	string enteredName;
	string enteredPassword;
	int position;
	int size;

	size = fileRead(username, password, SIZE);
	sort(username, password, size);
	//for (int count = 0; count < size; count++)
		//cout << username[count] << " " << password[count] << endl;

	cout << "Please enter your username and then your password.\n";
	cin >> enteredName >> enteredPassword;

	position = binarySearch(username, enteredName, size);
	//cout << position << endl;

	if (position == -1)
		cout << "Invalid Username.\n";
	else if (password[position] == enteredPassword)//position of parallel array keeps these in order
		cout << "You're logged in!\n";
	else
		cout << "Sorry, invalid password.\n";

	return 0;
}

int fileRead(string username[], string password[], int SIZE)
{
	ifstream inputFile;
	int index = 0;

	inputFile.open("passwords.txt");
	if (inputFile)
	{
		while (inputFile >> username[index] && inputFile >> password[index])
			index++;
		inputFile.close();
	}
	else
		cout << "The file did not open.";

	return index;
}

void sort(string username[], string password[], int SIZE)//swap for parallel arrays
{
	string temporaryUsername;//holds value before it is sorted
	string temporaryPassword;
	bool swap;

	do
	{
		swap = false;
		for (int count = 0; count < (SIZE - 1); count++)//should be actual size of array
		{
			if (username[count] >  username[count + 1])
			{
				//swap username positions
				temporaryUsername = username[count];
				username[count] = username[count + 1];
				username[count + 1] = temporaryUsername;

				//swap passwords as well
				temporaryPassword = password[count];
				password[count] = password[count + 1];
				password[count + 1] = temporaryPassword;

				swap = true;
			}
		}
	} while (swap);
}

int binarySearch(const string username[], string enteredName, int SIZE)
{
	int first = 0,
		last = SIZE - 1,
		middle,
		position = -1;
	bool found = false;

	while (!found && first <= last)//keep running until everything is checked, or it is found and flag flips
	{
		middle = (first + last) / 2;
		if (username[middle] == enteredName)//only found if it lands on it in the middle
		{
			found = true;
			position = middle;
		}
		else if (username[middle] > enteredName)
			last = middle - 1;//if username[middle] is greater than the entered name, the latter values are out
		else
			first = middle + 1;
	}
	return position;
}