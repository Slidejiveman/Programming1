#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string word;
	ifstream inputFile;
	string numbers;
	bool done = false;

	inputFile.open("test.txt");
	
	if (inputFile)
	{
		while (inputFile >> word && inputFile >> numbers)
		{
			cout << word  << " " <<  numbers << endl;
		}
	}
	else
		cout << "The file didn't open! XD\n";

	if (inputFile.eof())
	{
		done = true;
		cout << done << endl;
	}
	inputFile.close();

	return 0;
}
