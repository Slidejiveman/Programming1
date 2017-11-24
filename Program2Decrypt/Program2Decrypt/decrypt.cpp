//====================================================================
// Ryder Dale Walton
//1-30-15
//Programming Assignment #2
//Description: decrypt.cpp
//====================================================================

// Decryption algorithm program, meaning it accepts integers and returns
// characters.

#include <iostream>
#include <fstream>
using namespace std;

// Function prototype
char decryptRSA(int numCh, int secretKey, int bound);

//--------------------------------------------------------------------

void main()
{
	int messageLength; //for dynamic memory allocation
	int *messagePtr; //to use values element by element
	char decryptedChar; //to hold function return value
	ofstream outputFile; //to send output to .txt file

	//open outputFile
	outputFile.open("decrypt.txt");

	// Read in the message's length and allocate the memory needed by
	// the message buffer.
	if (outputFile)
	{
		cout << "Please input the length of the message as an integer. \n";
		cin >> messageLength;
		messagePtr = new int[messageLength];

		// Read the encrypted message.
		cout << "Please input your message using integers. \n";
		for (int i = 0; i < messageLength; i++)
			cin >> *(messagePtr + i);

		// Output the decrypted message character-by-character. Use
		// the secret key 23 and a bounding value of 143 to decrypt
		// the message.
		for (int i = 0; i < messageLength; i++)
		{
			decryptedChar = decryptRSA(*(messagePtr + i), 23, 143);
			cout << decryptedChar;
			outputFile << decryptedChar;
		}
		cout << endl;
		outputFile << endl;

		// Deallocate the memory used to store the message buffer.
		delete[] messagePtr;
		messagePtr = nullptr;

		//close outputFile
		outputFile.close();
	}
	else
		cout << "The outputfile did not open properly. Please restart the program. \n";
}

//--------------------------------------------------------------------

char decryptRSA(int numCh, int secretKey, int bound)

// Decrypts a character (numCh) that has been encrypted by the RSA
// public-key cryptosystem. Uses the specified secret key and bounding
// value.

{
	int temp,   // Stores intermediate result
		j;     // Loop counter

	// Compute
	//            secretKey
	//     ( numCh          ) % bound
	temp = numCh;
	for (j = 1; j < secretKey; j++)
		temp = (temp * numCh) % bound;
	return char(temp);
}