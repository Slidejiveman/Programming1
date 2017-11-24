#include <iostream>
#include <iomanip>
using namespace std;


void calculateWages(const int[], const int[], const double[], double[], const int);
void displayWages(const int[], const double[], const int);


int main()
{
	const int SIZE = 7;
	int empId[SIZE] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489 };
	int hours[SIZE] = { 40, 40, 40, 40, 40, 40, 40 };
	double payRate[SIZE] { 16.00, 16.00, 16.00, 16.00, 16.00, 16.00, 16.00};
	double wages[SIZE];

	calculateWages(empId, hours, payRate, wages, SIZE);
	displayWages(empId, wages, SIZE);


	return 0;
}

void calculateWages(const int empId[], const int hours[], const double payRate[], double wages[], const int SIZE)
{
	for (int index = 0; index < SIZE; index++)
	{
		empId[index];
		wages[index] = hours[index] * payRate[index];
	}
}

void displayWages (int const empId[], const double wages[], const int SIZE)
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Employee ID \t Wages.\n"
		<< "___________ \t _____\n";

	for (int index = 0; index < SIZE; index++)
	{
		cout << empId[index] << setw(16) << wages[index] << endl;
	}

}