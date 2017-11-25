//====================================================================
// Ryder Dale Walton
//2-25-15
//Programming Assignment #3
//Description: Bank Account Statement
//====================================================================

/*This program accepts a beginning balance from the user, and then reads in the
check amounts from a programmer created .txt file. It then converts these amounts to a 
binary file before it sorts the data into different configurations in order to print 
out 4 reports for the bank. As a rule of thumb, all files are opened and closed in each 
function in which they are used. This minimizes the number of failed file openings.*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

const int MAX = 60; //assumes that never more than 60 checks will be written

struct BankAccountType //associates all struct fields into one bankAccount type
{
	char date[12]; //date check was processed with room for '\0'
	char checkNum[8]; //number of assigned to the check
	float amount; //amount for which the check was processed
};

//function definitions
int readTXTFile(ifstream&, BankAccountType [], int); //returns number of elements read into struct array
void writeStructuredFile(ofstream&, BankAccountType [], int); //creates structured file with struxt array
void generateReport1(ifstream&, BankAccountType [], int); //displays the unsorted binary file
void generateReport2(BankAccountType [], int, float&, float&, float&); //displays sort by date and amount
void generateReport3(BankAccountType [], int, float&); //displays sort by check number w/o deposits
void generateReport4(BankAccountType [], int, float&); //displays sort of deposits by date and amount
void sortStructsByDate(BankAccountType[], int); //sorts structs by date and the amount of check
void sortStructsByCheckNum(BankAccountType[], int); //sorts structs by the check number

int main()
{
	BankAccountType bankAccount[MAX]; //array of structs to be sorted
	float beginningBalance; //receives initial balance from user
	float checkTotal = 0; //holds total of all checks written for the month
	float depositTotal = 0; //holds total of all deposits made for the month
	int elements = 0; //number of records read from .txt file, used as loop counter
	ifstream inputTXT; //raw account info from original .txt file
	ofstream structuredFileOut; //steam object used to write to binary file
	ifstream structuredFileIn; //stream object used to read from binary file

	//begin program processing proper
	do //get beginning balance from the user.
	{
		cout << "What is the beginning balance on the account?\n";
		cin >> beginningBalance;
	} while (beginningBalance < 0); //doesn't accept negative numbers

	//gather data from text file to fill struct array to be sorted
	elements = readTXTFile(inputTXT, bankAccount, elements);

	//write struct array contents to binary file
	writeStructuredFile(structuredFileOut, bankAccount, elements); //works with single
	
	//create first report and send its output to its local .txt file
	generateReport1(structuredFileIn, bankAccount, elements);

	//create the second report and send its output to its local .txt file
	generateReport2(bankAccount, elements, beginningBalance, checkTotal, depositTotal);
	
	//create the third report and send its output to its local.txt file
	generateReport3(bankAccount, elements, checkTotal);

	//create the fourth report and send its output to its local.txt file
	generateReport4(bankAccount, elements, depositTotal);

	//display to user that the report generation process is complete
	cout << "Report generation process complete. Please exit the program and collect your files.\n";

	return 0;
}
int readTXTFile(ifstream& inputTXT, BankAccountType bankAccount[], int elements)
{
	//open file stream and test
	inputTXT.open("bankAccountStatement2.txt"); 
	if (inputTXT.fail())
	{
		cout << "The bankAccountStatement2.txt file did not open properly.\n";
		return 0;
	}

	//read in values from the formatted .txt file into the fields of struct
	int i = 1; //counter
	//the redirectors work fine here since the programmer creates the .txt himself
	inputTXT >> bankAccount[0].date >> bankAccount[0].checkNum >> bankAccount[0].amount;//primed
	while (!inputTXT.eof())
	{
		//because the formatting of the text file is known, cin should work fine.
		//arrays are used here with the file read, though this is not what one would
		//do normally. The data for the array sorts has to be grabbed at some point.
		inputTXT >> bankAccount[i].date >> bankAccount[i].checkNum >> bankAccount[i].amount;
		i++;
	}
	elements = i;
	
	//close file and return
	inputTXT.close();
	return elements; //elements will by the for loop counter for the rest of the program
}
void writeStructuredFile(ofstream& structuredFileOut, BankAccountType bankAccount[], int elements)
{
	//open structured file
	structuredFileOut.open("bankAccountStatement.dat", ios::binary);
	if (!structuredFileOut)
	{
		cout << "The structured (binary) file did not open properly.\n";
		return;
	}

	//write data in struct array to binary file
	for (int i = 0; i < elements; i++)
	{
		structuredFileOut.write(reinterpret_cast<char *>(&bankAccount[i]), sizeof(bankAccount[i]));
	}

	//close file
	structuredFileOut.close();
}
void generateReport1(ifstream& structuredFileIn, BankAccountType bankAccount[], int elements)
{
	//open files and test them
	ofstream report1Output("report1Output.txt");
	structuredFileIn.open("bankAccountStatement.dat", ios::binary);
	if (!report1Output)
	{
		cout << "Report 1's output file did not open.\n";
		return;
	}
	if (!structuredFileIn)
	{
		cout << "The structured (binary) file did not open properly.\n";
		return;
	}

	//display header of report one
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(12) << "Date" << left << setw(12) 
		<< "Check#/Deposit" << right << setw(8) << "Amount\n";
	report1Output << fixed << showpoint << setprecision(2);
	report1Output << left << setw(12) << "Date" << left << setw(12) 
		<< "Check#/Deposit" << right << setw(8) << "Amount\n";

	//read file contents back in as a test. If they are overwritten incorrectly, couts will show this.
	for (int i = 0; i < elements; i++)
	{
		structuredFileIn.read(reinterpret_cast<char *>(&bankAccount[i]), sizeof(bankAccount[i]));
		cout << left << setw(12)<< bankAccount[i].date 
			<< left << setw(12) << bankAccount[i].checkNum 
			<< right << setw(8) << bankAccount[i].amount << endl;
		report1Output << left << setw(12) << bankAccount[i].date 
			<< left << setw(12) << bankAccount[i].checkNum 
			<< right << setw(8) << bankAccount[i].amount << endl;
	}

	//close files
	report1Output.close();
	structuredFileIn.close();
}
void generateReport2(BankAccountType bankAccount[], int elements, float& beginningBalance, 
						float& checkTotal, float& depositTotal)
{
	//local variables
	float endingBalance = 0; //gross amount earned or lost during the month

	//open file and test open
	ofstream report2Output("report2Output.txt");
	if (report2Output.fail())
	{
		cout << "Report 2's output file did not open.\n";
		return;
	}

	//sort the array of structs according to date as well as check amount in a given day
	sortStructsByDate(bankAccount, elements);

	//display header of report two
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(12) << "Date" << left << setw(12) 
		<< "Check#/Deposit" << right << setw(8) << "Amount\n";
	report2Output << fixed << showpoint << setprecision(2);
	report2Output << left << setw(12) << "Date" << left << setw(12) 
		<< "Check#/Deposit" << right << setw(8) << "Amount\n";

	//display the rest of the contents and write them to file
	for (int i = 0; i < elements; i++)
	{
		cout << left << setw(12) << bankAccount[i].date << left << setw(12) << bankAccount[i].checkNum
			<< right << setw(8) << bankAccount[i].amount << endl;
		report2Output << left << setw(12) << bankAccount[i].date << left << setw(12) 
			<< bankAccount[i].checkNum << right << setw(8) << bankAccount[i].amount << endl;
	}

	//calculate the total lines
	for (int i = 0; i < elements; i++)
	{
		if (isalpha(bankAccount[i].checkNum[0]))//tried with strcmp too, neither work
			depositTotal += bankAccount[i].amount;//convert c-strings to float
		else
			checkTotal += bankAccount[i].amount;
	}
	endingBalance = (beginningBalance + depositTotal) - checkTotal;

	//display balances
	cout << endl <<"Beginning Balance: $" << beginningBalance << endl << endl;
	cout << "Check Total: $" << checkTotal << endl << endl;
	cout << "Deposit Total: $" << depositTotal << endl << endl;
	cout << "Ending Balance: $" << endingBalance << endl << endl;
	report2Output << endl << "Beginning Balance: $" << beginningBalance << endl << endl;
	report2Output << "Check Total: $" << checkTotal << endl << endl;
	report2Output << "Deposit Total: $" << depositTotal << endl << endl;
	report2Output << "Ending Balance: $" << endingBalance << endl << endl;

	//close file
	report2Output.close();
}
void generateReport3(BankAccountType bankAccount[], int elements, float& checkTotal)
{
	//open local file and test
	ofstream report3Output("report3Ouput.txt");
	if (report3Output.fail())
	{
		cout << "Report 3's ouput file did not open.\n";
		return;
	}

	//sort structs by check number
	sortStructsByCheckNum(bankAccount, elements);

	//display structs as newly sorted and write them out to file
	//display header of report 3
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(12) << "Date" << left << setw(12) << "Check#/Deposit" 
		<< right << setw(8) << "Amount\n";
	report3Output << fixed << showpoint << setprecision(2);
	report3Output << left << setw(12) << "Date" << left << setw(12) << "Check#/Deposit" 
		<< right << setw(8) << "Amount\n";

	//display the rest of the contents and write them to file
	for (int i = 0; i < elements; i++)
	{
		if (!isalpha(bankAccount[i].checkNum[0]))
		{
			cout << left << setw(12) << bankAccount[i].date << left << setw(12) 
				<< bankAccount[i].checkNum
				<< right << setw(8) << bankAccount[i].amount << endl;
			report3Output << left << setw(12) << bankAccount[i].date << left << setw(12) 
				<< bankAccount[i].checkNum
				<< right << setw(8) << bankAccount[i].amount << endl;
		}
	}

	//display check total line
	cout << endl << "Check Total: $" << checkTotal << endl << endl;
	report3Output << endl << "Check Total: $" << checkTotal << endl << endl;

	//close file
	report3Output.close();
}
void generateReport4(BankAccountType bankAccount[], int elements, float& depositTotal)
{
	//open output file
	ofstream report4Output("report4Output.txt");
	if (report4Output.fail())
	{
		cout << "Report 4's output file did not open.\n";
		return;
	}

	//sort structs by date
	sortStructsByDate(bankAccount, elements);

	//display header and write it to file
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(12) << "Date" << left << setw(12) << "Check#/Deposit" 
		<< right << setw(8) << "Amount\n";
	report4Output << fixed << showpoint << setprecision(2);
	report4Output << left << setw(12) << "Date" << left << setw(12) << "Check#/Deposit" 
		<< right << setw(8) << "Amount\n";

	//display structs, only deposits, and write them to file
	for (int i = 0; i < elements; i++)
	{
		if (isalpha(bankAccount[i].checkNum[0]))
		{
			cout << left << setw(12) << bankAccount[i].date << left << setw(12) << bankAccount[i].checkNum
				<< right << setw(8) << bankAccount[i].amount << endl;
			report4Output << left << setw(12) << bankAccount[i].date << left << setw(12) << bankAccount[i].checkNum
				<< right << setw(8) << bankAccount[i].amount << endl;
		}
	}

	//display deposit total
	cout << endl << "Deposit Total: $" << depositTotal << endl << endl;
	report4Output << endl << "Deposit Total: $" << depositTotal << endl << endl;


	//close file
	report4Output.close();
}
void sortStructsByDate(BankAccountType bankAccount[], int elements)
{
	bool swap; //controls do-while loop
	BankAccountType temp; //placeholder for the actual swap process

	//the compiler actually does allow one to assign struct variables to one
	//another. So, these sorts move the records around struct by struct
	//rather than field by field because the former is more efficient.
	do
	{
		swap = false;
		for (int count = 0; count < (elements - 1); count++)
		{
			//sorts everything according to date, lowest first
			if (strcmp(bankAccount[count].date, bankAccount[count + 1].date) > 0)
			{
				temp = bankAccount[count];
				bankAccount[count] = bankAccount[count + 1];
				bankAccount[count + 1] = temp;
				swap = true;
			}

			//sorts the elements with equal dates by check amount, lowest first
			if (strcmp(bankAccount[count].date, bankAccount[count + 1].date) == 0 && 
				bankAccount[count].amount > bankAccount[count + 1].amount)
			{
				temp = bankAccount[count];
				bankAccount[count] = bankAccount[count + 1];
				bankAccount[count + 1] = temp;
				swap = true;
			}
		}

	} while (swap);
}
void sortStructsByCheckNum(BankAccountType bankAccount[], int elements)
{
	bool swap; //controls do-while loop
	BankAccountType temp; //placeholder for the actual swap process

	do
	{
		swap = false;
		for (int count = 0; count < (elements - 1); count++)
		{
			//sorts everything according to date, lowest first
			if (strcmp(bankAccount[count].checkNum, bankAccount[count + 1].checkNum) > 0)
			{
				temp = bankAccount[count];
				bankAccount[count] = bankAccount[count + 1];
				bankAccount[count + 1] = temp;
				swap = true;
			}
		}

	} while (swap);
}