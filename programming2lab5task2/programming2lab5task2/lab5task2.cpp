#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Employee
{
	int idNum,
	    hoursWorked;
	float hourlyPayRate;;
	float taxRate;
};

int main()
{
	Employee employeeInfo[5];
	float grossPay[5], netPay[5];
	ofstream outputFile("lab5task2.txt");
	
    //collect employeeID from the keyboard
	for (int i = 0; i < 5; i++)
	{
		cout << "Please enter the ID Number for employee # " << (i + 1) << ". \n";
		cin >> employeeInfo[i].idNum;
	}

	//collect hours worked from the keyboard
	for (int i = 0; i < 5; i++)
	{
		cout << "Please enter the hours worked for employee # " << (i + 1) << ". \n";
		cin >> employeeInfo[i].hoursWorked;
	}

	//collect rate of pay from the keyboard
	for (int i = 0; i < 5; i++)
	{
		cout << "Please enter the pay rate for employee # " << (i + 1) << ". \n";
		cin >> employeeInfo[i].hourlyPayRate;
	}

    //collect tax rate from the keyboard
	for (int i = 0; i < 5; i++)
	{
		cout << "Please enter the tax rate for employee # " << (i + 1) << "as a whole number. \n";
		cin >> employeeInfo[i].taxRate;

        //calculate tax rate as a decimal
		employeeInfo[i].taxRate /= 100;
	}

    //calculate Gross and Net Pay
	for (int i = 0; i < 5; i++)
	{
		if (employeeInfo[i].hoursWorked > 40)//account for time and a half
		    grossPay[i] = (40 * employeeInfo[i].hourlyPayRate) 
                            + ((employeeInfo[i].hoursWorked - 40) * (employeeInfo[i].hourlyPayRate * 1.5));
		else
		    grossPay[i] = employeeInfo[i].hoursWorked * employeeInfo[i].hourlyPayRate;
       
        netPay[i] = grossPay[i] - (grossPay[i] * employeeInfo[i].taxRate);//should be the same regardless
	}

    //display results
	cout << fixed << showpoint << setprecision(2);
	outputFile << fixed << showpoint << setprecision(2);
	cout << "ID   Hours Worked Rate Of Pay Tax Rate(%) Gross Pay Net Pay\n";
	outputFile << "ID   Hours Worked Rate Of Pay Tax Rate(%) Gross Pay Net Pay\n";
	for (int i = 0; i < 5; i++)
	{
		cout << left << setw(8) << employeeInfo[i].idNum << left << setw(8) 
             << employeeInfo[i].hoursWorked << "\t" << left << setw(8) 
             << employeeInfo[i].hourlyPayRate << left << setw(8) 
             << (employeeInfo[i].taxRate * 100) << left << setw(8) << grossPay[i] 
             << left << setw(8) << netPay[i] << endl;
		outputFile << left << setw(8) << employeeInfo[i].idNum << left << setw(8) 
            << employeeInfo[i].hoursWorked << "\t" << left << setw(8) 
            << employeeInfo[i].hourlyPayRate << left << setw(8)
			<< (employeeInfo[i].taxRate * 100) << left << setw(8) << grossPay[i]
			<< left << setw(8) << netPay[i] << endl;
	}

    //close outputFile
	outputFile.close();
	return 0;
}