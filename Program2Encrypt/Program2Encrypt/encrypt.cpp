//====================================================================
// Ryder Dale Walton
//1-30-15
//Programming Assignment #2
//Description: encrypt.cpp
//====================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function prototype
int encryptRSA(char ch, int publicKey, int bound);

//--------------------------------------------------------------------

void main()
{
	int messageLength; // to dynamically allocate memory
	string unencryptedMessage; // text data grabbed from user
	char *messagePtr; // used to access individual chars of string
	int encryptedInt; //holds return value from encryptRSA function
	ofstream outputFile; // to send output to .txt file

	//open outputFile
	outputFile.open("encrypt.txt");

	// Read in the message's length and allocate the memory needed by
	// the message buffers.
	if (outputFile)
	{
		cout << "Please input the length of the message as an integer. \n";
		cin >> messageLength;
		messagePtr = new char[messageLength];

		// Read in the unencrypted message -- need to first skip over the
		// newline marker.
		cout << "Please input your message as a string of characters. \n";
		cin.get(); //a precaution, to skip return character in keyboard buffer
		getline(cin, unencryptedMessage);

		//convert string to character array
		for (int i = 0; i < messageLength; i++)
		{
			*(messagePtr + i) = unencryptedMessage[i];
		}
		
		// Encrypt the message character-by-character. Use the public
		// key 47 and a bounding value of 143 to encrypt the message.
		// Also, output the data
		cout << messageLength << " ";
		outputFile << messageLength << " ";
		for (int i = 0; i < messageLength; i++)
		{
			encryptedInt = encryptRSA(*(messagePtr +i), 47, 143);
			cout << encryptedInt << " ";;
			outputFile << encryptedInt << " ";
		}
		cout << endl;
		outputFile << endl;

		// Deallocate the memory used to store the message buffers.
		delete  [] messagePtr;
		messagePtr = nullptr;

		// close output file
		outputFile.close();
	}
	else
		cout << "The output file did not open successfully. Please close the program.\n";
}

//--------------------------------------------------------------------

int encryptRSA(char ch, int publicKey, int bound)

// Encrypts a character (ch) using the RSA public-key cryptosystem and
// the specified public key and bounding value.

{
	int temp,   // Stores intermediate result
		j;     // Loop counter

	// Compute
	//         publicKey
	//     ( ch          ) % bound

	temp = ch;
	for (j = 1; j < publicKey; j++)
		temp = (temp * ch) % bound;
	return temp;
}