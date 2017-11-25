#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Student
{
	int idNum,
	creditPts,
	creditHours;
	double gpa;
};

int main()
{
	Student studentInfo[6];
	ofstream outputFile("lab5task1.txt");

	//collect student ID numbers from the keyboard
	for (int i = 0; i < 6; i++)
	{
		cout << "Please enter the ID Number for student # " << (i + 1) << ". \n";
		cin >> studentInfo[i].idNum;
	}

	//collect student credit points from the keyboard
	for (int i = 0; i < 6; i++)
	{
		cout << "Please enter the credit points for student # " << (i + 1) << ". \n";
		cin >> studentInfo[i].creditPts;
	}

	//collect student credit hours from the keyboard
	for (int i = 0; i < 6; i++)
	{
		cout << "Please enter the credit hours for student # " << (i + 1) << ". \n";
		cin >> studentInfo[i].creditHours;
	}

	//calculate gpa
	for (int i = 0; i < 6; i++)
	{
		studentInfo[i].gpa = static_cast<double>(studentInfo[i].creditPts)
												/ studentInfo[i].creditHours;
	}

	//display and format values
	cout << fixed << showpoint << setprecision(2);
	outputFile << fixed << showpoint << setprecision(2);
	cout << "ID \t Credit Points \t Credit Hours \t GPA\n";
	outputFile << "ID \t Credit Points \t Credit Hours \t GPA\n";
	for (int i = 0; i < 6; i++)
	{
		cout << studentInfo[i].idNum << "\t\t" << studentInfo[i].creditPts << "\t\t"
			<< studentInfo[i].creditHours << "\t" << studentInfo[i].gpa << endl;
		outputFile << studentInfo[i].idNum << "\t\t" << studentInfo[i].creditPts << "\t\t"
			<< studentInfo[i].creditHours << "\t" << studentInfo[i].gpa << endl;
	}

	//close outputFile
	outputFile.close();
	return 0;
}