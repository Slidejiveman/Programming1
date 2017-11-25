#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ofstream outputFile; //to print output

	//open outputFile
	outputFile.open("lab4task1.txt");
	//define array to work with
	char names[8][10] = { "Robert", "James", "Wesley", "Marcus", 
						"Randy", "Brandon", "Jeanette", "Darra" };
	//process and display the 2D array backwards
	for (int i = 7; i >= 0 ; i--)
	{
		for (int j = 9; j >= 0; j--)
		{
			if (names[i][j] != '\0')
			{
				cout << names[i][j];
				outputFile << names[i][j];
			}
		}
		cout << endl;
		outputFile << endl;
	}

	return 0;
}