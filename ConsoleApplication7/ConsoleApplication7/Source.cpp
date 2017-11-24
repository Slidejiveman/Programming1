#include <iostream>
using namespace std;

int main()
{
	char choice;

	cout << "Enter A, B, or C: \n";
	cin >> choice;

	switch (choice)
	{
	case 'A':
		cout << "You chose A.";
		break;

	case 'B':
		cout << "You chose B.";
		break;

	case 'C':
		cout << "You chose C.";
		break;

	default:
		cout << "That is not a valid choice.\n";
	}

	return 0;
}