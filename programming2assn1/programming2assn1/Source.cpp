//====================================================================
// Ryder Dale Walton
//1-13-15
//Programming Assignment #1
//Description: Mortgage Calculations
//====================================================================

/*This program gives the user three options. The two functions calculate
a monthly payment, along with all of the calculations necessary for an 
amortization table, and print said table to an output file.*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//function prototypes
double calculateMonthlyPayment(double&, double&, double&, int&, int&);
void printAmortTable(double, double, double, double, int, int, ofstream&);

int main()
{
	//variable declarations
	int menuChoice; //allows program to branch between three options
	double monthlyPayment;//holds return value from calculate function
	double principal;//original amount of loan, passed to functions
	double rate;//more specifically, this is the interest rate
	int years;//length of loan to be converted into months
	int months; //necessary conversion for sake of the equation
	double monthlyPercentRate; //this value is 1/12 of the rate entered
	ofstream outputFile;//necessary to write data to .txt document

	//create the output file and check if creation was successful.
	outputFile.open("mortgageData.txt");
	if (outputFile)
	{
		//the program gives the user three options.
		do //the do-while loop is for input validation
		{
			cout << "What would you like to do? Enter 1, 2, or 3.\n"
				<< "1. Calculate a monthly payment\n"
				<< "2. Print an amortization table\n"
				<< "3. Quit\n";
			cin >> menuChoice;
		} while (menuChoice <1 || menuChoice > 3);
	}

	//based on menuChoice, the program has branches.
	if (menuChoice == 1)
	{
		//call monthlyPayment function, assign return value
		monthlyPayment = calculateMonthlyPayment(principal, rate, 
												monthlyPercentRate, years, months);
		
		//display the monthly payment and write to a file
		cout << fixed << showpoint << setprecision(2);
		outputFile << fixed << showpoint << setprecision(2);

		cout << "Monthly Payment: \n"
			<< "Principal: " << principal << endl
			<< "Annual Interest Rate: " << rate << endl
			<< "Term: " << years  << " years" << endl
			<< "Payments: " << monthlyPayment << endl;
		outputFile << "Monthly Payment: \n"
			<< "Principal: $" << principal << endl
			<< "Annual Interest Rate: " << rate << "%" << endl
			<< "Term: " << years << " years" << endl
			<< "Payments: $" << monthlyPayment << endl;
	}

	//option two prints the amortization table
	if (menuChoice == 2)
	{

		//call monthlyPayment function, assign return value
		monthlyPayment = calculateMonthlyPayment(principal, rate, 
													monthlyPercentRate, years, months);

		//call printAmortTable function, parameters by value
		printAmortTable(monthlyPayment, principal, rate, monthlyPercentRate, 
							years, months, outputFile);
	}

	//option three thanks the user and stops the program
	if (menuChoice == 3)
		cout << "Thank you for using this program. Close the window "
			<< "anytime\n";

	//close the file
	outputFile.close();

	return 0;
}

//output is printed in main to demonstrate pass by reference
double calculateMonthlyPayment(double &principal, double &rate, 
								double &monthlyPercentRate, int &years, int&months)
{
	//function variables
	double monthlyPayment; //value to be returned to main
	double decimalRate; //holds conversion from annual rate entered as a percentage

	//ask the user to enter the principle, interest rate, and years
	cout << "Please enter the principal on the loan.\n";
	cin >> principal;
	cout << "Next, enter the interest rate at as a percentage.\n";
	cin >> rate;
	cout << "Finally, enter the number of years on the loan.\n";
	cin >> years;

	//make necessary caluclations and conversions
	decimalRate = rate / 100;//convert percentage to a decimal value
	monthlyPercentRate = decimalRate / static_cast<float>(12);//convert rate to monthly rate for equation
	months = years * 12;//convert years to months for equation

	//calculate the monthly payment
	monthlyPayment = (monthlyPercentRate * principal) / (1 - (1 / (pow((1 + monthlyPercentRate), months))));

	return monthlyPayment;
}

//output is printed in function because it is void and the name suggests so
void printAmortTable(double monthlyPayment, double principal, double rate, 
						double monthlyPercentRate, int years, int months, ofstream& outputFile)
{
	//function variables
	int paymentNumber;//counter for loop, compared against months in the loan
	double interest;//dollar amount found when decimalRate * principal
	double paidOnPrincipal;//monthlyPayment - interest, amount paid off of loan

	//display and write the headers of the table
	cout << fixed << showpoint << setprecision(2);
	outputFile << fixed << showpoint << setprecision(2);

	cout << "\t\t\tMortgage Amortization Table\n\n"
		<< "\t\t\t    Loan: $" << principal << endl
		<< "\t\t\t\tRate: " << rate << "%\n" 
		<< "\t\t\t\tYears: " << years << "\n"
		<< "\t\t\tMonthly Payment: $" << monthlyPayment << endl << endl;
	cout << "Payment\tBeginning\t\t\t\tPaid On\n"
		<< "Number\tBalance\t    Payment\t   Interest\tPrincipal\tNewBalance\n\n";
	outputFile << "\t\t\tMortgage Amortization Table\n\n"
		<< "\t\t\t    Loan: $" << principal << endl
		<< "\t\t\t\tRate: " << rate << "%\n"
		<< "\t\t\t\tYears: " << years << "\n"
		<< "\t\t\tMonthly Payment: $" << monthlyPayment << endl << endl;
	outputFile << "Payment\tBeginning\t\t\t\tPaid On\n"
		<< "Number\tBalance\t    Payment\t   Interest\tPrincipal\tNewBalance\n\n";

	//main table loop
	for (paymentNumber = 1; paymentNumber <= months; paymentNumber++)
	{
		//check to see if this iteration will be the last payment
		if (paymentNumber == months)
		{
			interest = principal * monthlyPercentRate;
			monthlyPayment = principal + interest;//final payment must be remaining balance
		}

		//the loop prints as it calculates so that arrays are not needed
		if (paymentNumber <= 6 || paymentNumber >= (months - 5))//prints original values
		{
			//print out currently held values
			cout << left << setw(6) << paymentNumber << "\t" << setw(10) << principal << "   " << setw(7) 
				<< monthlyPayment << "\t  ";
			outputFile << left << setw(6) << paymentNumber << "\t" << setw(10) << principal << "   " << setw(7)
				<< monthlyPayment << "\t  ";
		}
		if (paymentNumber == 7)//add blank lines
		{
			cout << endl << endl << endl;
			outputFile << endl << endl << endl;
		}

		//calculate interest, paid on principal, and new balance
		if (paymentNumber < months)//on final iteration, must be calculated before payment.
		{
			interest = principal * monthlyPercentRate;	
		}
		
		//calculations regardless of iteration
		paidOnPrincipal = monthlyPayment - interest;
		principal = principal - paidOnPrincipal;
		
		if (paymentNumber <= 6 || paymentNumber >= (months - 5))//prints calculated values
		{
			//print out results of calculations, .005 added to round values to change amounts
			cout << setw(8) << (interest + .005) << "\t  " << setw(6) << paidOnPrincipal << "\t" << principal << endl;
			outputFile << setw(8) << (interest + .005) << "\t" << setw(6) << paidOnPrincipal << "\t" << principal << endl;
		}

	}
}