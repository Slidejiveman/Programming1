#include <iostream>
using namespace std;

int main()

{
	char character;
	int integer = 0;

	cout << "Give a character.\n";
	cin >> character;

	cout << "Here is its integer value: " << (int) character << endl;

	cout << "Give an integer.\n";
	cin >> integer;

	cout << "Here is its character value: " << (char)integer << endl;

	for (int count = 1; count <= 127; count++)
	{
		cout << (char)count << endl;
		if (count % 16 == 0)
			cout << endl;
	}
	return 0;
}